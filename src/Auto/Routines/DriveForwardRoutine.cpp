/*
 zzb * DriveForwardRoutine.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "DriveForwardRoutine.h"

DriveForwardRoutine::DriveForwardRoutine(RobotModel *robot, DriveController* kDrive, Profile* profile, GearController *gearController, LightsController* lights) {
	this->robot = robot;
	this->kDrive = kDrive;
	this->profile = profile;
	this->lights = lights;
	this->gearController = gearController;
}

void DriveForwardRoutine::Routine() {
	DriveInterval(profile, 10, 193.0);
}

void DriveForwardRoutine::Prestart() {

}

