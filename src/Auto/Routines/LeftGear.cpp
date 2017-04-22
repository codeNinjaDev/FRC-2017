/*
 * LeftGear.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "LeftGear.h"

LeftGear::LeftGear(VisionController *vision, RobotModel *robot, DriveController* driveTrain, GearController* gearController, LightsController* lights) {
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->vision = vision;
    this->lights = lights;
    this->gearController = gearController;

}

void LeftGear::Prestart() {

}

void LeftGear::Routine() {
	gearController->GearPIDUp();
	NewStraight(robot, driveTrain, gearController, lights, 90.5, 0.45, 4.0, 0.4);
	DriveDistanceRotate(robot, driveTrain, 70, 0.6, 1.6, true, lights);
	NewStraight(robot, driveTrain, gearController, lights, 25.0, 0.45, 2.5, 0.4);
	gearController->GearDown();
	WaitTime(0.05);
	DriveDistanceStraight(robot, driveTrain, gearController, -9.0, 0.25, 1.5, true, lights, true);
}
