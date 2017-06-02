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
	DriveDistanceStraight(controllers, 61.0, 0.4, 4.0, true, false);
	DriveDistanceStraight(controllers, 25.0, 0.25, 2.0, false, false);
    controllers->GetGearController()->GearPIDDown();
	DriveDistanceStraight(controllers, -5.0, 0.25, 1.5, true, true);
	controllers->GetRobotModel()->SetGearIntakeSpeed(0.0);
}

void CenterGear::Prestart() {
}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

