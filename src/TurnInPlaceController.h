/*
 * TurnInPlaceController.h
 *
 *  Created on: Apr 6, 2017
 *      Author: kidco
 */

#ifndef SRC_TURNINPLACECONTROLLER_H_
#define SRC_TURNINPLACECONTROLLER_H_
#include "TrajectoryFollower.h"
#include "DriveSignal.h"
#include "Pose.h"
#include "TrajectoryFollowingPositionController.h"
#include "ProfileController.h"
class TurnInPlaceController : public ProfileController{
 public:
    TurnInPlaceController(Pose* poseToContinueFrom, double destHeading, double velocity);
    DriveSignal* Update(Pose* pose);
    Pose* GetCurrentSetpoint();
    bool OnTarget();
    double GetHeadingGoal();
    virtual ~TurnInPlaceController();
 private:
    TrajectoryFollowingPositionController* mController;
    Pose* mSetpointRelativePose;
};

#endif /* SRC_TURNINPLACECONTROLLER_H_ */
