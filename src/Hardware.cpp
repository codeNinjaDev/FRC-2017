/*
 Hardware.cpp

 Created on: Jan 27, 2017
 Author: peter
 */

#include <Hardware.h>

static RobotModel *robot = new RobotModel();
static RemoteControl *humanControl = new ControlBoard();

Hardware::Hardware() {
  // TODO Auto-generated destructor stub
}

RobotModel* Hardware::GetRobot() {
  return robot;
}

RemoteControl* Hardware::GetHumanControl() {
  return humanControl;
}
static DriveController *driveController = new DriveController(Hardware::GetRobot(), Hardware::GetHumanControl());
static DashboardLogger *dashboardLogger = new DashboardLogger(Hardware::GetRobot(), Hardware::GetHumanControl());
DriveController* Hardware::GetDriveController() {
  return driveController;
}

DashboardLogger* Hardware::GetDashboardLogger() {
  return dashboardLogger;
}

Hardware::~Hardware() {
  // TODO Auto-generated destructor stub
}

