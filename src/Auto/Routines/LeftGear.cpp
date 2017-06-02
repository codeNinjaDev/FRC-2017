/*
 * LeftGear.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "LeftGear.h"

LeftGear::LeftGear(MasterController* controllers) {
    this->controllers = controllers;

}

void LeftGear::Prestart() {

}

void LeftGear::Routine() {
   DriveDistanceStraight(controllers, 93.96, 0.5, 3.3, true, false);
   DriveDistanceRotate(controllers, 73, 0.6, 1.5, true);
  // DriveDistanceStraight(robot, driveTrain, 2, 1.0, 1, false);
   DriveDistanceStraight(controllers, 30, 0.4, 5, false, false);
}
// 15in 129v
