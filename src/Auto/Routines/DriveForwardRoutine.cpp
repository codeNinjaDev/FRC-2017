/*
 zzb * DriveForwardRoutine.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "DriveForwardRoutine.h"

DriveForwardRoutine::DriveForwardRoutine(MasterController* controllers) {
    this->controllers = controllers;
}

void DriveForwardRoutine::Routine() {
	DriveDistanceStraight(controllers, 193.0, 0.8, 10.0, false, false);
}

void DriveForwardRoutine::Prestart() {

}

