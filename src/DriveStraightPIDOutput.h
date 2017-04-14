/*
 * DriveStraightPIDOutput.h
 *
 *  Created on: Apr 11, 2017
 *      Author: kidco
 */

#ifndef SRC_DRIVESTRAIGHTPIDOUTPUT_H_
#define SRC_DRIVESTRAIGHTPIDOUTPUT_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
class DriveStraightPIDOutput : public PIDOutput {
 public:
    DriveStraightPIDOutput(RobotDrive *drive, RobotModel* robot);

    //Override PIDWrite
    void PIDWrite(double output);
 private:
    RobotModel* robot;
    RobotDrive *drive;
};

#endif /* SRC_DRIVESTRAIGHTPIDOUTPUT_H_ */
