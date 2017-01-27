/*
 * Hardware.h
 *
 *  Created on: Jan 27, 2017
 *      Author: peter
 */

#ifndef SRC_HARDWARE_H_
#define SRC_HARDWARE_H_
#include "RobotModel.h"
#include "DriveController.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
#include "DashboardLogger.h"



class Hardware {
public:
  Hardware();
  static RobotModel* GetRobot();
  static RemoteControl* GetHumanControl();
  static DriveController* GetDriveController();
  static DashboardLogger* GetDashboardLogger();
  RobotModel const *robot = new RobotModel();
  RemoteControl const *humanControl = new ControlBoard();
  DriveController const *driveController = new DriveController(GetRobot(), GetHumanControl());
  DashboardLogger const *dashboardLogger = new DashboardLogger(GetRobot(), GetHumanControl());
  virtual ~Hardware();
private:


};

#endif /* SRC_HARDWARE_H_ */
