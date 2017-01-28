/*
 Hardware.cpp

 Created on: Jan 27, 2017
 Author: peter
 */

#include <Hardware.h>

static RobotModel *robot = new RobotModel();
static RemoteControl *humanControl = new ControlBoard();
static DriveController *driveController = new DriveController(robot, humanControl);
static DashboardLogger *dashboardLogger = new DashboardLogger(robot, humanControl);

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

Hardware::~Hardware() {
  // TODO Auto-generated destructor stub
}

