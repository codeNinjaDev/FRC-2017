#ifndef DRIVEROTATEMOTORSPIDOUTPUT_H_
#define DRIVEROTATEMOTORSPIDOUTPUT_H_

#include "WPILib.h"
#include "../Hardware/RobotModel.h"
#include "../Hardware/RemoteControl.h"

class DriveRotateMotorsPIDOutput: public PIDOutput {
public:
    DriveRotateMotorsPIDOutput(RobotDrive *drive);

	//Override PIDWrite
	void PIDWrite(double output);

private:
    RobotDrive *drive;
};

#endif
