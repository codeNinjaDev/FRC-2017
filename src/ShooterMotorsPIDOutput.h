#ifndef SHOOTERMOTORSPIDOUTPUT_H_
#define SHOOTERMOTORSPIDOUTPUT_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"

class ShooterMotorsPIDOutput : public PIDOutput{
public:
	ShooterMotorsPIDOutput(Victor *kOutputMotor1, Victor *kOutputMotor2);
  
    //Override PIDWrite
	void PIDWrite(double output);

	double GetPIDLoopOutput();

private:
	double loopOutput;

	Victor *shooterMotorA;
	Victor *shooterMotorB;
};

#endif
