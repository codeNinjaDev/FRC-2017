/*
 * BoilerFirstHopper.cpp
 *
 *  Created on: Mar 18, 2017
 *      Author: mikec
 */

#include "Auto/Routines/BoilerFirstHopper.h"

BoilerFirstHopper::BoilerFirstHopper(MasterController* controllers) {
    this->controllers = controllers;
}

void BoilerFirstHopper::Routine() {
	DriveDistanceStraight(controllers, 27.0*12.0, 0.8, 9, false, false);
	WaitTime(1.0);
	DriveDistanceRotate(controllers, 75.0, 0.8, 1.5, false);
	DriveDistanceStraight(controllers, -20, 0.8, 2.5, false, false);
	DriveDistanceRotate(controllers, 69.0, 0.8, 1.5, false);
	DriveDistanceStraight(controllers, -100, 0.8, 7, false, false);
}

void BoilerFirstHopper::Prestart() {

}

