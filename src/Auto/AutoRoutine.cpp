/*
 * AutoRoutine.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#include "AutoRoutine.h"
#include "AutoBase.h"

void AutoRoutine::DriveInterval(double seconds, double y, double x) {

  AutoBase::RunAction(new DriveIntervalAction(seconds, y, x));
}

void AutoRoutine::Shoot(double seconds, double speed) {
  AutoBase::RunAction(new ShootAction(seconds, speed));
}

AutoRoutine::~AutoRoutine(){

}

