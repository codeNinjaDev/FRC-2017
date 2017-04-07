/*
 * TrajectoryFollowingPositionController.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: kidco
 */

#include <TrajectoryFollowingPositionController.h>

TrajectoryFollowingPositionController::TrajectoryFollowingPositionController(double kp, double ki,
        double kd, double kv, double ka, double on_target_delta, TrajectoryFollower::TrajectoryConfig* config) {

    m_follower = new TrajectoryFollower();
    m_follower->Configure(kp, ki, kd, kv, ka, config);
    m_on_target_delta = on_target_delta;

// TODO Auto-generated constructor stub

}

void TrajectoryFollowingPositionController::SetGoal(TrajectoryFollower::TrajectorySetPoint* current_state, double goal_position) {
    m_goal = goal_position;
    m_follower->SetGoal(current_state, goal_position);
}
double TrajectoryFollowingPositionController::GetGoal() {

    return m_follower->GetGoal();
}
void TrajectoryFollowingPositionController::SetConfig(TrajectoryFollower::TrajectoryConfig* config) {
    m_follower->SetConfig(config);

}
TrajectoryFollower::TrajectoryConfig* TrajectoryFollowingPositionController::GetConfig() {
    return m_follower->GetConfig();
}
void TrajectoryFollowingPositionController::Update(double position, double velocity) {
    m_error = m_goal - position;
    m_result = m_follower->Calculate(position, velocity);
}
TrajectoryFollower::TrajectorySetPoint* TrajectoryFollowingPositionController::GetSetPoint() {
    return m_follower->GetCurrentSetpoint();
}
double TrajectoryFollowingPositionController::Get() {
    return m_result;
}

void TrajectoryFollowingPositionController::Reset() {
    m_result = 0;
    m_error = 0;
    m_follower->SetGoal(m_follower->GetCurrentSetpoint(), m_goal);
}
bool TrajectoryFollowingPositionController::IsFinishedTrajectory() {
    return m_follower->IsFinishedTrajectory();
}
bool TrajectoryFollowingPositionController::IsOnTarget() {
    return m_follower->IsFinishedTrajectory() && fabs(m_error) < m_on_target_delta;
}
TrajectoryFollowingPositionController::~TrajectoryFollowingPositionController() {
}

