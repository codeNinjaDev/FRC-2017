/*
 * TrajectoryFollower.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: kidco
 */

#include <TrajectoryFollower.h>
#include <Timer.h>
#include <math.h>
TrajectoryFollower::TrajectoryFollower() {
    reset = true;
    next_state = new TrajectorySetPoint();
    config = new TrajectoryConfig();
    setpoint = new TrajectorySetPoint();
}

string TrajectoryFollower::TrajectoryConfig::ToString() {
    return "dt: " + to_string(dt) + ", max_acc: " + to_string(max_acc)
            + ", max_vel: " + to_string(max_vel);
}

string TrajectoryFollower::TrajectorySetPoint::ToString() {
    return "pos: " + to_string(pos) + ", vel: " + to_string(vel) + ", acc: "
            + to_string(acc);
}

void TrajectoryFollower::Configure(double kp, double ki, double kd, double kv,
                                   double ka, TrajectoryConfig* config) {
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    this->kv = kv;
    this->ka = ka;
    this->config = config;
}

void TrajectoryFollower::SetGoal(TrajectorySetPoint* current_state,
                                 double goal_position) {
    this->goal_position = goal_position;
    this->setpoint = current_state;
    this->reset = true;
    this->error_sum = 0.0;
}
double TrajectoryFollower::GetGoal() {
    return goal_position;
}

double TrajectoryFollower::Calculate(double pos, double vel) {
        double dt = config->dt;
       if (!reset) {
       double now = Timer::GetFPGATimestamp();
       dt = now - last_timestamp;
       last_timestamp = now;
       } else {
       last_timestamp = Timer::GetFPGATimestamp();
       }

       if (IsFinishedTrajectory()) {
       setpoint->pos = goal_position;
       setpoint->vel = 0;
       setpoint->acc = 0;

       } else {
       double distance_to_go = goal_position - setpoint->pos;
       double cur_vel = setpoint->vel;
       double cur_vel2 = cur_vel * cur_vel;
       bool inverted = false;
       if (distance_to_go < 0) {
       inverted = true;
       distance_to_go *= 1;
       cur_vel *= -1;
       }

       double max_reachable_velocity_disc = cur_vel2 / 2.0
       + config->max_acc * distance_to_go;
       double min_reachable_velocity_disc = cur_vel2 / 2.0
       - config->max_acc * distance_to_go;
       double cruise_vel = cur_vel;
       if (min_reachable_velocity_disc < 0 || cruise_vel < 0) {
       cruise_vel = fmin(config->max_vel, sqrt(max_reachable_velocity_disc));

       }
       double t_start = (cruise_vel - cur_vel) / config->max_acc;
       double x_start = cur_vel * t_start
       + .5 * config->max_acc * t_start * t_start;
       double t_end = fabs(cruise_vel / config->max_acc);
       double x_end = cruise_vel * t_end - .5 * config->max_acc * t_end * t_end;
       double x_cruise = fmax(0, distance_to_go - x_start - x_end);
       double t_cruise = fabs(x_cruise / cruise_vel);

       if (t_start >= dt) {
       next_state->pos = cur_vel * dt + .5 * config->max_acc * dt * dt;
       next_state->vel = cur_vel + config->max_acc * dt;
       next_state->acc = config->max_acc;
       } else if (t_start + t_cruise >= dt) {
       next_state->pos = x_start + cruise_vel * (dt - t_start);
       next_state->vel = cruise_vel;
       next_state->acc = 0;
       } else if (t_start + t_cruise + t_end >= dt) {
       double delta_t = dt - t_start - t_cruise;
       next_state->pos = x_start + x_cruise + cruise_vel * delta_t
       - .5 * config->max_acc * delta_t * delta_t;
       next_state->vel = cruise_vel - config->max_acc * delta_t;
       next_state->acc = -config->max_acc;
       } else {
       // Trajectory ends this cycle->
       next_state->pos = distance_to_go;
       next_state->vel = 0;
       next_state->acc = 0;
       }

       if (inverted) {
       next_state->pos *= -1;
       next_state->vel *= -1;
       next_state->acc *= -1;

       }
       setpoint->pos += next_state->pos;
       setpoint->vel = next_state->vel;
       setpoint->acc = next_state->acc;
       }
       double error = setpoint->pos - pos;

       if (reset) {
       reset = false;
       last_error = error;
       error_sum = 0;
       current_segment = 0;
       }
       double output = kp * error
       + kd * ((error - last_error) / dt - setpoint->vel)
       + (kv * setpoint->vel + ka * setpoint->acc);
       if (output < 1.0 && output > -1.0) {
       error_sum += error * dt;
       }

       output += ki * error_sum;

       last_error = error;
       return output;
}

TrajectoryFollower::TrajectoryConfig* TrajectoryFollower::GetConfig() {
    return config;
}

void TrajectoryFollower::SetConfig(TrajectoryConfig* config) {
    this->config = config;
}

double TrajectoryFollower::LegacyCalculate(double distance_so_far) {

    if (current_segment < profile->GetNumSegments()) {
    Trajectory::Segment* segment = profile->GetSegment(current_segment);
    double error = segment->pos - distance_so_far;
    double output = kp * error
            + kd * ((error - last_error) / segment->dt - segment->vel)
            + (kv * segment->vel + ka * segment->acc);

    last_error = error;
    current_heading = segment->heading;
    current_segment++;
    return output;
    } else {
    return 0;
    }
}
bool TrajectoryFollower::IsFinishedTrajectory() {
    return fabs(setpoint->pos - goal_position) < 1E-3
            && fabs(setpoint->vel) < 1E-2;
}
TrajectoryFollower::TrajectorySetPoint* TrajectoryFollower::GetCurrentSetpoint() {
    return setpoint;
}
Trajectory::Segment* TrajectoryFollower::GetCurrentSegment() {
    return profile->GetSegment(current_segment);
}

void TrajectoryFollower::Reset() {
    last_error = 0.0;
    current_segment = 0;
}

double TrajectoryFollower::GetHeading() {
    return current_heading;
}
int TrajectoryFollower::GetNumSegments() {
    return profile->GetNumSegments();
}
TrajectoryFollower::~TrajectoryFollower() {
    // TODO Auto-generated destructor stub
}

