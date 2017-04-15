/*
 * Blank2.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#include "Blank2.h"

Blank2::Blank2(RobotModel* robot, DriveController* driveTrain,
		GearController* gearController, LightsController* lights) {
	this->robot = robot;
	this->driveTrain = driveTrain;
	this->gearController = gearController;
	this->lights = lights;
}

void Blank2::Prestart() {

}
void Blank2::Routine() {
	gearController->GearPIDUp();
	NewStraight(robot, driveTrain, gearController, lights, 90.0, 0.45, 4.0, 0.4);
	DriveDistanceRotate(robot, driveTrain, 75, 0.6, 1.6, true, lights);
	NewStraight(robot, driveTrain, gearController, lights, 30.0, 0.45, 2.5, 0.4);
	gearController->GearDown();
	DriveDistanceStraight(robot, driveTrain, gearController, -5.0, 0.25, 1.5, true, lights, true);


}

Blank2::~Blank2() {
	// TODO Auto-generated destructor stub
}

