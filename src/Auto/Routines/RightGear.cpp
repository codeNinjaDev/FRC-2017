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
    controllers->GetGearController()->GearRest();
}

void RightGear::Routine() {

    controllers->GetGearController()->GearPIDUp();
    NewStraight(controllers, 93.2, 0.45, 4.0,
                0.4);
    DriveDistanceRotate(controllers, -70, 0.6, 1.6, true);
    NewStraight(controllers, 30.0, 0.45, 2.5,
                0.4);
    controllers->GetGearController()->GearDown();
    DriveDistanceStraight(controllers, -5.0, 0.25, 1.5,
                          true, true);

}
