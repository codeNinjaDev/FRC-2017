/*
 * DrivePathController.h
 *
 *  Created on: Apr 5, 2017
 *      Author: kidco
 */

#ifndef SRC_DRIVEPATHCONTROLLER_H_
#define SRC_DRIVEPATHCONTROLLER_H_
#include "TrajectoryFollower.h"
#include "Path.h"
#include "Pose.h"
#include "DriveSignal.h"
#include "DriveController.h"
#include "ProfileController.h"
class DrivePathController : public ProfileController {
 public:
    DrivePathController(Path* path);

    Trajectory* trajectory;
    TrajectoryFollower* followerLeft;
    TrajectoryFollower* followerRight;
    double direction, heading, kTurn;

    bool OnTarget();
    void Reset();
    int GetFollowerCurrentSegmentNumber();
    int GetNumSegments();
    void SetTrajectory(Trajectory* t);
    double GetGoal();

    DriveSignal* Update(Pose* pose);
    Pose* GetCurrentSetpoint();
    virtual ~DrivePathController();

 private:
    void init();
    void LoadProfile(Trajectory* leftProfile, Trajectory* rightProfile,
                     double direction, double heading);
    void LoadProfileNoReset(Trajectory* leftProfile, Trajectory* rightProfile);
};

#endif /* SRC_DRIVEPATHCONTROLLER_H_ */
