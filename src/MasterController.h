/*
 * MasterController.h
 *
 *  Created on: Apr 10, 2017
 *      Author: kidco
 */

#ifndef SRC_MASTERCONTROLLER_H_
#define SRC_MASTERCONTROLLER_H_

#include "Controllers/LightsController.h"
#include "Controllers/VisionController.h"
#include "Controllers/DriveController.h"
#include "Hardware/RobotModel.h"
#include "Controllers/GearController.h"

class MasterController {
 public:
    MasterController(VisionController* vision, RobotModel* robot,
                     DriveController* driveTrain, GearController* gearController, LightsController* lights);
    VisionController* GetVisionController();
    RobotModel* GetRobotModel();
    DriveController* GetDriveController();
    GearController* GetGearController();
    LightsController* GetLightsController();

 private:
     VisionController* vision;
     RobotModel* robot;
     DriveController* driveTrain;
     GearController* gearController;
     LightsController* lights;
};

#endif /* SRC_MASTERCONTROLLER_H_ */
