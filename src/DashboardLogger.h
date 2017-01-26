/*
 * DashboardLogger.h
 *
 *  Created on: Jan 12, 2017
 *      Author: mikec
 */

#ifndef SRC_DASHBOARDLOGGER_H_
#define SRC_DASHBOARDLOGGER_H_

#include "RobotModel.h"
#include "RemoteControl.h"

class DashboardLogger {
public:
  DashboardLogger();
  virtual ~DashboardLogger();

  void UpdateData();

private:


  void PutDriveMotorCurrentData();
  void PutRobotCurrentData();
  void PutDriverJoystickAxesData();
  void PutOperatorJoystickAxesData();
  void PutDriverMotorOutputs();
};

#endif /* SRC_DASHBOARDLOGGER_H_ */
