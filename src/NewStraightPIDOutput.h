/*
 * WheelsPIDOutput.h
 *
 *  Created on: Mar 7, 2017
 *      Author: michael
 */

#ifndef SRC_NEWSTRAIGHTPIDOUTPUT_H_
#define SRC_NEWSTRAIGHTPIDOUTPUT_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"

class NewStraightPIDOutput : public PIDOutput {
public:
	NewStraightPIDOutput(RobotDrive *drive, RobotModel *robot);

	//Override PIDWrite
	void PIDWrite(double output);

	double GetPIDLoopOutput();

	double loopOutput;
	double kPencoder = 0.7; //0.625
private:

	RobotDrive* drive;
	RobotModel* robot;

};

#endif
