/*
 * DriveInterval.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#include <Auto/Action/DriveIntervalAction.h>
double goal_time;
double start_time;

double x_drive;
double y_drive;
DriveController* kDrive;

DriveIntervalAction::DriveIntervalAction(double seconds, double y, double x) {
  goal_time = seconds;
  x_drive = x;
  y_drive = y;

}
bool isFinished() {
  return (Timer::GetFPGATimestamp() >= start_time + goal_time);
}

void update() {
  driveController->ArcadeDrive(x_drive, y_drive, false);
}

void done() {
  driveController->Stop();
}

void start() {
  start_time = Timer::GetFPGATimestamp();
}
DriveIntervalAction::~DriveIntervalAction() {
  // TODO Auto-generated destructor stub
}

