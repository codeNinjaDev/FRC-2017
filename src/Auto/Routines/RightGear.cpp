/*
 * RightGear.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "RightGear.h"

RightGear::RightGear(MasterController* controllers) {
    this->controllers = controllers;

}

void RightGear::Prestart() {

}

void RightGear::Routine() {
	   DriveDistanceStraight(controllers, 98, 0.5, 3.3, true, false);
	   DriveDistanceRotate(controllers, -73, 0.6, 1.5, true);
	   DriveDistanceStraight(controllers, 10, 1.0, 1, false, false);
	   DriveDistanceStraight(controllers, 15, 0.4, 5, false, false);

}
