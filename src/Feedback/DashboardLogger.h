/*
 * DashboardLogger.h
 *
 *  Created on: Jan 12, 2017
 *      Author: mikec
 */

#ifndef SRC_DASHBOARDLOGGER_H_
#define SRC_DASHBOARDLOGGER_H_

#include "../Hardware/RobotModel.h"
#include "../Hardware/RemoteControl.h"

class DashboardLogger {
public:
	DashboardLogger(RobotModel*, RemoteControl*);
	virtual ~DashboardLogger();

	void UpdateData();
	void UpdateEssentialData();

private:
	RobotModel *robot;
	RemoteControl *humanControl;

	void PutDriveMotorCurrentData();
	void PutRobotCurrentData();
	void PutShooterEncoderData();
	void PutDriveEncoderData();
	void PutShooterMotorOutputs();
	void PutDriverJoystickAxesData();
	void PutOperatorJoystickAxesData();
	void PutDriverMotorOutputs();
	void PutGamePadButtonPress();
};

#endif /* SRC_DASHBOARDLOGGER_H_ */
