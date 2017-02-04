/*
 Hardware.cpp

 Created on: Jan 27, 2017
 Author: peter
 */

#include "Hardware.h"

static RobotModel *robot = new RobotModel();
static RemoteControl *humanControl = new ControlBoard();
static ShooterController *shooter = new ShooterController(robot, humanControl);
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

ShooterController* Hardware::GetShooterController() {
  return shooter;
}

Hardware::~Hardware() {
  // TODO Auto-generated destructor stub
}

