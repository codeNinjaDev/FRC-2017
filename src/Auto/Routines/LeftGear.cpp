/*
 * LeftGear.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "LeftGear.h"

LeftGear::LeftGear(MasterController* controller) {
    this->vision = controller->GetVisionController();
    this->robot = controller->GetRobotModel();
    this->driveTrain = controller->GetDriveController();
    this->lights = controller->GetLightsController();
    this->gearController = controller->GetGearController();

}

void LeftGear::Prestart() {

}

void LeftGear::Routine() {
   DriveDistanceStraight(robot, driveTrain, gearController, 93.96, 0.5, 3.3, true, lights, false);
   DriveDistanceRotate(robot, driveTrain, 73, 0.6, 1.5, true, lights);
  // DriveDistanceStraight(robot, driveTrain, 2, 1.0, 1, false);
   DriveDistanceStraight(robot, driveTrain, gearController, 30, 0.4, 5, false, lights, false);
}
// 15in 129v
