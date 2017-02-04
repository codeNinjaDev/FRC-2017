/*
 * DriveInterval.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */
#include "Timer.h"
#include "DriveIntervalAction.h"


DriveIntervalAction::DriveIntervalAction(double seconds, double y, double x) {
  goal_time = seconds;
  x_drive = x;
  y_drive = y;
  start_time = 0;
}

bool DriveIntervalAction::IsFinished() {
  return (Timer::GetFPGATimestamp() >= start_time + goal_time);
}

void DriveIntervalAction::Update() {
  kDrive->ArcadeDrive(x_drive, y_drive, false);
}

void DriveIntervalAction::Done() {
  kDrive->Stop();
}

void DriveIntervalAction::Start() {
  start_time = Timer::GetFPGATimestamp();
}

DriveIntervalAction::~DriveIntervalAction() {
}

