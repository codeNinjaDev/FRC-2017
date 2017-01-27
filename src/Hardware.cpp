/*
Hardware.cpp

Created on: Jan 27, 2017
Author: peter
*/

#include <Hardware.h>

Hardware::Hardware() {
  // TODO Auto-generated destructor stub
}

RobotModel* Hardware::GetRobot() {
  return robot;
}

RemoteControl* Hardware::GetHumanControl() {
  return humanControl;
}

DriveController* Hardware::GetDriveController() {
  return driveController;
}

DashboardLogger* Hardware::GetDashboardLogger() {
  return dashboardLogger;
}

LiveWindow* Hardware::GetLiveWindow() {
  return lw;
}

Hardware::~Hardware() {
  // TODO Auto-generated destructor stub
}

