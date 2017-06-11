/*
 * Blank3.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#include "Blank3.h"

Blank3::Blank3(MasterController* controllers) {
    this->controllers = controllers;
}

void Blank3::Prestart() {

}
void Blank3::Routine() {
	DriveDistanceStraight(robot, driveTrain, gearController, 27.0*12.0, 0.8, 9, false, lights, false);
	WaitTime(1.0);
	DriveDistanceRotate(robot, driveTrain, -75.0, 0.8, 1.5, false, lights);
	DriveDistanceStraight(robot, driveTrain, gearController, -20, 0.8, 2.5, false, lights, false);
	DriveDistanceRotate(robot, driveTrain, -69.0, 0.8, 1.5, false, lights);
	DriveDistanceStraight(robot, driveTrain, gearController, -100, 0.8, 7, false, lights, false);
}


Blank3::~Blank3() {
    // TODO Auto-generated destructor stub
}

