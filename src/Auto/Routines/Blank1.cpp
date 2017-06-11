/*
 * Blank1.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#include "Blank1.h"

Blank1::Blank1(MasterController* controllers) {
    this->controllers = controllers;
}

void Blank1::Prestart() {

}
void Blank1::Routine() {
	gearController->GearPIDUp();
	NewStraight(robot, driveTrain, gearController, lights, 70.0, 0.4, 3.0, 0.4);
	gearController->GearDown();
	DriveDistanceStraight(robot, driveTrain, gearController, -5.0, 0.25, 1.5, true, lights, true);
}


Blank1::~Blank1() {
    // TODO Auto-generated destructor stub
}

