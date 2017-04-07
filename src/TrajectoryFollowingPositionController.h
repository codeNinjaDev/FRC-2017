/*
 * TrajectoryFollowingPositionController.h
 *
 *  Created on: Apr 5, 2017
 *      Author: kidco
 */

#ifndef SRC_TRAJECTORYFOLLOWINGPOSITIONCONTROLLER_H_
#define SRC_TRAJECTORYFOLLOWINGPOSITIONCONTROLLER_H_
#include "WPILib.h"
#include "TrajectoryFollower.h"
class TrajectoryFollowingPositionController {
 public:
    TrajectoryFollower* m_follower;
    double m_goal;
    double m_error;
    double m_on_target_delta;
    double m_result = 0;
    TrajectoryFollowingPositionController(
            double kp, double ki, double kd, double kv, double ka,
            double on_target_delta,
            TrajectoryFollower::TrajectoryConfig* config);
    void SetGoal(TrajectoryFollower::TrajectorySetPoint* current_state, double goal);
    double GetGoal();
    void SetConfig(TrajectoryFollower::TrajectoryConfig* config);
    TrajectoryFollower::TrajectoryConfig* GetConfig();
    void Update(double position, double velocity);
    TrajectoryFollower::TrajectorySetPoint* GetSetPoint();
    double Get();
    void Reset();
    bool IsFinishedTrajectory();
    bool IsOnTarget();
    virtual ~TrajectoryFollowingPositionController();
};

#endif /* SRC_TRAJECTORYFOLLOWINGPOSITIONCONTROLLER_H_ */
