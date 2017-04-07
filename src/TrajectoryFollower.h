/*
 * TrajectoryFollower.h
 *
 *  Created on: Apr 5, 2017
 *      Author: kidco
 */

#ifndef SRC_TRAJECTORYFOLLOWER_H_
#define SRC_TRAJECTORYFOLLOWER_H_
#include <iostream>
#include "Trajectory.h"
using namespace std;
class TrajectoryFollower {
 public:

    class TrajectoryConfig {
     public:
        double dt;
        double max_acc;
        double max_vel;

        string ToString();
    };
    class TrajectorySetPoint {
     public:
        double pos;
        double vel;
        double acc;

        string ToString();
    };
    TrajectoryFollower();
    void Configure(double kp, double ki, double kd, double kv,
                   double ka, TrajectoryConfig* config);
    void SetGoal(TrajectorySetPoint* current_state, double goal_position);
    double GetGoal();
    TrajectoryConfig* GetConfig();
    void SetConfig(TrajectoryConfig* config);
    double Calculate(double pos, double vel);
    double LegacyCalculate(double distance_to_go);
    bool IsFinishedTrajectory();
    void SetTrajectory(Trajectory* profile);
    double GetHeading();
    Trajectory::Segment* GetCurrentSegment();
    int GetCurrentSegmentNumber();
    int GetNumSegments();
    void Reset();
    TrajectorySetPoint* GetCurrentSetpoint();
    virtual ~TrajectoryFollower();
 private:
    double kp;
    double ki;
    double kd;
    double kv;
    double ka;
    double last_error;
    double error_sum;
    double current_heading;
    int current_segment;
    bool reset;
    double last_timestamp;
    double goal_position;
    TrajectorySetPoint* next_state;
    Trajectory* profile;
    TrajectoryConfig* config;
    TrajectorySetPoint* setpoint;

};

#endif /* SRC_TRAJECTORYFOLLOWER_H_ */
