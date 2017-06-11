/*
 * NewStraightPIDOutput.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: michael
 */

#include "NewStraightPIDOutput.h"
#include "WPILib.h"

NewStraightPIDOutput::NewStraightPIDOutput(RobotDrive *drive, RobotModel *robot){
	 this->drive = drive;
	 this->robot = robot;
}

void NewStraightPIDOutput::PIDWrite(double output){
	loopOutput = output;
    drive->ArcadeDrive(output, robot->GetEncoderError() * kPencoder, false);
    SmartDashboard::PutNumber("ArcadeCORRECTION", robot->GetEncoderError() * kPencoder);
    SmartDashboard::PutNumber("auton_EncoderError", robot->GetEncoderError());
}

double NewStraightPIDOutput::GetPIDLoopOutput() {
	return loopOutput;
}
