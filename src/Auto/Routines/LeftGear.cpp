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
	NewStraight(robot, driveTrain, gearController, lights, 89.0, 0.45, 4.0, 0.4);
	DriveDistanceRotate(robot, driveTrain, 70, 0.6, 1.6, true, lights);
	NewStraight(robot, driveTrain, gearController, lights, 30.0, 0.45, 2.5, 0.4);
	gearController->GearDown();
	DriveDistanceStraight(robot, driveTrain, gearController, -5.0, 0.25, 1.5, true, lights, true);
}
