#ifndef DRIVEYMOTORSPIDOUTPUT_H_
#define DRIVEYMOTORSPIDOUTPUT_H_

#include "WPILib.h"
#include "../Hardware/RobotModel.h"
#include "../Hardware/RemoteControl.h"

class DriveYMotorsPIDOutput: public PIDOutput {
public:
    DriveYMotorsPIDOutput(RobotDrive *drive);

	//Override PIDWrite
	void PIDWrite(double output);

private:
    RobotDrive *drive;
};

#endif
