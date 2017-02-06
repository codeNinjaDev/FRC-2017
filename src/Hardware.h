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
#include "SuperstructureController.h"
#include "ShooterController.h"



class Hardware {
public:
  Hardware();

  RobotModel* GetRobot();
  RemoteControl* GetHumanControl();
  DriveController* GetDriveController();
  DashboardLogger* GetDashboardLogger();
  ShooterController* GetShooterController();
  SuperstructureController* GetSuperstructureController();
  virtual ~Hardware();
private:


};

#endif /* SRC_HARDWARE_H_ */
