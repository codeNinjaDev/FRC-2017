/*
 Hardware.cpp

 Created on: Jan 27, 2017
 Author: peter
 */

#include "Hardware.h"
static RobotModel *robot = new RobotModel();
static RemoteControl *humanControl = new ControlBoard();
static DriveController *driveController = new DriveController(robot, humanControl);
static DashboardLogger *dashboardLogger = new DashboardLogger(robot, humanControl);
static ShooterController *shooter = new ShooterController(robot, humanControl);
static SuperstructureController *superstructure = new SuperstructureController(robot, humanControl);

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

ShooterController* Hardware::GetShooterController() {
  return shooter;
}

SuperstructureController* Hardware::GetSuperstructureController() {
  return superstructure;
}



Hardware::~Hardware() {
  // TODO Auto-generated destructor stub
}

