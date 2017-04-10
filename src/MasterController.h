/*
 * MasterController.h
 *
 *  Created on: Apr 10, 2017
 *      Author: kidco
 */

#ifndef SRC_MASTERCONTROLLER_H_
#define SRC_MASTERCONTROLLER_H_

#include "LightsController.h"
#include "VisionController.h"
#include "DriveController.h"
#include "RobotModel.h"
#include "GearController.h"
#include "MotionController.h"

class MasterController {
 public:
    MasterController(VisionController* vision, RobotModel* robot,
                     DriveController* driveTrain, GearController* gearController,
                     MotionController* motion, LightsController* lights);
    VisionController* GetVisionController();
    RobotModel* GetRobotModel();
    DriveController* GetDriveController();
    GearController* GetGearController();
    MotionController* GetMotionController();
    LightsController* GetLightsController();

 private:
     VisionController* vision;
     RobotModel* robot;
     DriveController* driveTrain;
     GearController* gearController;
     MotionController* motion;
     LightsController* lights;
};

#endif /* SRC_MASTERCONTROLLER_H_ */
