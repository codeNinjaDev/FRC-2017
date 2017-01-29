/*
 * DriveInterval.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */
#include "Timer.h"
#include "DriveIntervalAction.h"
double goal_time;
double start_time;
double x_drive;
double y_drive;

DriveIntervalAction::DriveIntervalAction(double seconds, double y, double x) {
  goal_time = seconds;
  x_drive = x;
  y_drive = y;

}
bool DriveIntervalAction::isFinished() {
  return (Timer::GetFPGATimestamp() >= start_time + goal_time);
}

void DriveIntervalAction::update() {
  kDrive->ArcadeDrive(x_drive, y_drive, false);
}

void DriveIntervalAction::done() {
  kDrive->Stop();
}

void DriveIntervalAction::start() {
  start_time = Timer::GetFPGATimestamp();
}
DriveIntervalAction::~DriveIntervalAction() {
  // TODO Auto-generated destructor stub
}

