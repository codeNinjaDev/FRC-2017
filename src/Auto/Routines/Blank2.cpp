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
	DriveDistanceStraight(robot, driveTrain, gearController, 27.0*12.0, 0.8, 9, false, lights, false);
	WaitTime(1.0);
}

Blank2::~Blank2() {
	// TODO Auto-generated destructor stub
}

