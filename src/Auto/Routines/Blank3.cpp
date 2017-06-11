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
	DriveDistanceStraight(controllers, 27.0*12.0, 0.8, 9, false, false);
	WaitTime(1.0);
	DriveDistanceRotate(controllers, -75.0, 0.8, 1.5, false);
	DriveDistanceStraight(controllers, -20, 0.8, 2.5, false, false);
	DriveDistanceRotate(controllers, -69.0, 0.8, 1.5, false);
	DriveDistanceStraight(controllers, -100, 0.8, 7, false, false);
}


Blank3::~Blank3() {
    // TODO Auto-generated destructor stub
}

