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

   controllers->GetGearController()->GearPIDUp();
   NewStraight(controllers, 90.5, 0.45, 4.0, 0.4);
   DriveDistanceRotate(controllers, 70, 0.6, 1.6, true);
   NewStraight(controllers, 25.0, 0.45, 2.5, 0.4);
   controllers->GetGearController()->GearDown();
   WaitTime(0.05);
   DriveDistanceStraight(controllers, -9.0, 0.25, 1.5, true, true);

}
