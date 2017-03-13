/*
 * CenterGear.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "CenterGear.h"

CenterGear::CenterGear(RobotModel *robot, DriveController* driveTrain) {
  this->robot = robot;
  this->driveTrain = driveTrain;
}

void CenterGear::Routine() {
	//FROM CENTER of ALLIANCE WALL

}

void CenterGear::Prestart() {}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

