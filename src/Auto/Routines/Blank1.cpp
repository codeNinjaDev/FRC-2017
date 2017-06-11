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
    controllers->GetGearController()->GearPIDUp();
	NewStraight(controllers, 70.0, 0.4, 3.0, 0.4);
	controllers->GetGearController()->GearDown();
	DriveDistanceStraight(controllers, -5.0, 0.25, 1.5, true, true);
}


Blank1::~Blank1() {
    // TODO Auto-generated destructor stub
}

