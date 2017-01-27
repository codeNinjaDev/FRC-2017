/*
 * HARDWARE.h
 *
 *  Created on: Jan 21, 2017
 *      Author: peter
 */

#ifndef SRC_HARDWARE_H_
#define SRC_HARDWARE_H_


#include "RobotModel.h"
#include "DriveController.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
#include "DashboardLogger.h"


static RobotModel *robot = new RobotModel();
static RemoteControl *humanControl = new ControlBoard();
static DriveController *driveController = new DriveController(robot, humanControl);
static DashboardLogger *dashboardLogger = new DashboardLogger(robot, humanControl);
static LiveWindow *lw;




#endif /* SRC_HARDWARE_H_ */
