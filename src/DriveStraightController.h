/*
 * DriveStraightController.h
 *
 *  Created on: Apr 6, 2017
 *      Author: kidco
 */

#ifndef SRC_DRIVESTRAIGHTCONTROLLER_H_
#define SRC_DRIVESTRAIGHTCONTROLLER_H_
#include "TrajectoryFollower.h"
#include "Pose.h"
#include "DriveSignal.h"
#include "DriveController.h"
#include "TrajectoryFollowingPositionController.h"
#include "ProfileController.h"
class DriveStraightController : public ProfileController{
 public:
    DriveStraightController(Pose* priorSetpoint, double goalSetpoint, double maxVelocity, DriveController* driveTrain);
    DriveSignal* Update(Pose* currentPose);
    Pose* GetCurrentSetpoint();
    static double encoderDistance(Pose* pose);

    static double encoderVelocity(Pose* pose);
    bool OnTarget();
    virtual ~DriveStraightController();

 private:
    TrajectoryFollowingPositionController* mDistanceController;
    Pose* mSetpointRelativePose;
    DriveController* driveTrain;
};

#endif /* SRC_DRIVESTRAIGHTCONTROLLER_H_ */
