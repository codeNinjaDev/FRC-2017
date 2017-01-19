/*
 * DriveInterval.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#include <Auto/Action/DriveInterval.h>
double goal_time;
double start_time;

double x_drive;
double y_drive;
DriveController* kDrive;

DriveInterval::DriveInterval(DriveController* drive, double seconds, double y, double x) {
  goal_time = seconds;
  x_drive = x;
  y_drive = y;
  kDrive = drive;
}
bool isFinished() {
  return (Timer::GetFPGATimestamp() >= start_time + goal_time);
}

void update() {
  kDrive->ArcadeDrive(x_drive, y_drive, false);
}

void done() {
  kDrive->Stop();
}

void start() {
  start_time = Timer::GetFPGATimestamp();
}
DriveInterval::~DriveInterval() {
  // TODO Auto-generated destructor stub
}

