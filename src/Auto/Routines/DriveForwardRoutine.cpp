/*
 zzb * DriveForwardRoutine.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "DriveForwardRoutine.h"

DriveForwardRoutine::DriveForwardRoutine(MasterController* controller) {
	this->robot = controller->GetRobotModel();
	this->kDrive = controller->GetDriveController();
	this->lights = controller->GetLightsController();
	this->gearController = controller->GetGearController();
}

void DriveForwardRoutine::Routine() {
	DriveDistanceStraight(robot, kDrive, gearController, 193.0, 0.8, 10.0, false, lights, false);
}

void DriveForwardRoutine::Prestart() {

}

