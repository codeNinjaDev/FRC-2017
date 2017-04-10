/*
 * CenterGear.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "CenterGear.h"
CenterGear::CenterGear(MasterController* controller) {
    this->vision = controller->GetVisionController();
    this->robot = controller->GetRobotModel();
    this->driveTrain = controller->GetDriveController();
    this->lights = controller->GetLightsController();
    this->gearController = controller->GetGearController();
}
void CenterGear::Routine() {
	gearController->GearPIDUp();
	DriveDistanceStraight(robot, driveTrain, gearController, 61.0, 0.4, 4.0, true, lights, false);
	DriveDistanceStraight(robot, driveTrain, gearController, 25.0, 0.25, 2.0, false, lights, false);
	gearController->GearPIDDown();
	DriveDistanceStraight(robot, driveTrain, gearController, -5.0, 0.25, 1.5, true, lights, true);
	robot->SetGearIntakeSpeed(0.0);
}

void CenterGear::Prestart() {
}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

