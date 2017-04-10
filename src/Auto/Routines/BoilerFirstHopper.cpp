/*
 * BoilerFirstHopper.cpp
 *
 *  Created on: Mar 18, 2017
 *      Author: mikec
 */

#include "Auto/Routines/BoilerFirstHopper.h"

BoilerFirstHopper::BoilerFirstHopper(MasterController* controller) {
    this->robot = controller->GetRobotModel();
    this->driveTrain = controller->GetDriveController();
    this->lights = controller->GetLightsController();
    this->gearController = controller->GetGearController();
}

void BoilerFirstHopper::Routine() {
	DriveDistanceStraight(robot, driveTrain, gearController, 27.0*12.0, 0.8, 9, false, lights, false);
	WaitTime(1.0);
	DriveDistanceRotate(robot, driveTrain, 75.0, 0.8, 1.5, false, lights);
	DriveDistanceStraight(robot, driveTrain, gearController, -20, 0.8, 2.5, false, lights, false);
	DriveDistanceRotate(robot, driveTrain, 69.0, 0.8, 1.5, false, lights);
	DriveDistanceStraight(robot, driveTrain, gearController, -100, 0.8, 7, false, lights, false);
}

void BoilerFirstHopper::Prestart() {

}

