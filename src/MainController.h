/*
 * MainController.h
 *
 *  Created on: Jan 21, 2017
 *      Author: peter
 */

#ifndef SRC_MAINCONTROLLER_H_
#define SRC_MAINCONTROLLER_H_

#include "DashboardLogger.h"

#include "WPILib.h"
#include "RobotModel.h"
#include "DriveController.h"
#include "RemoteControl.h"
#include "ControlBoard.h"

static RobotModel *robot = new RobotModel();
static RemoteControl *humanControl = new ControlBoard();
static DriveController *driveController = new DriveController();
static DashboardLogger *dashboardLogger = new DashboardLogger();
static LiveWindow *lw;




#endif /* SRC_MAINCONTROLLER_H_ */
