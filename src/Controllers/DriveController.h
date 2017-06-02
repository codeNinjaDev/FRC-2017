#ifndef DRIVECONTROLLER_H_
#define DRIVECONTROLLER_H_

#include "WPILib.h"
#include "../Hardware/RobotModel.h"
#include "../Hardware/RemoteControl.h"
#include "../PID/DriveYMotorsPIDOutput.h"
#include "../PID/DriveRotateMotorsPIDOutput.h"
#include "../PID/DriveEncodersPIDSource.h"
#include "../PID/WheelsPIDOutput.h"
#include "../Feedback/DashboardLogger.h"
#include "../Controllers/VisionController.h"
#include "../PID/VisionPIDSource.h"
#include "../Feedback/ini.h"
#include <iostream>

class PivotCommand;

class DriveController {
public:
	DriveController(RobotModel *myRobot, RemoteControl *myHumanControl, VisionController *myVision);
	virtual ~DriveController();

	void Stop();
	void Update(double currTimeSec, double deltaTimeSec);
	void Reset();
	void ArcadeDrive(double myX, double myY, bool teleOp);
	void TankDrive(double myLeft, double myRight);
	  void RefreshIni();

	enum DriveState {
		kInitialize, kTeleopDrive
	};


	PIDOutput *leftPIDOutput;
	PIDController *leftPID;

	PIDOutput *rightPIDOutput;
	PIDController *rightPID;

	PIDOutput *driveXPIDOutput;
	PIDController *visionPID;
	VisionPIDSource *visionPIDSource;

	DriveEncodersPIDSource *driveEncodersPIDSource; //average of two drive encoders
    VisionController *vision;

private:
  RobotModel *robot;
  RemoteControl *humanControl;
  double testVariable;
  double test2Variable;
  RobotDrive *driveTrain;
  uint32_t m_stateVal;
  uint32_t nextState;
};

#endif
