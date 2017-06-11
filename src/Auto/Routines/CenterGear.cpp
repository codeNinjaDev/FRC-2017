/*
 * CenterGear.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "CenterGear.h"
CenterGear::CenterGear(MasterController* controllers) {
    this->controllers = controllers;

}
void CenterGear::Routine() {
	controllers->GetGearController()->GearPIDUp();
    NewStraight(controllers, 75.0, 0.3, 4.0, 0.4);
    controllers->GetGearController()->GearDown();
	DriveDistanceStraight(controllers, -5.0, 0.25, 1.5, true, true);
}

void CenterGear::Prestart() {
}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

