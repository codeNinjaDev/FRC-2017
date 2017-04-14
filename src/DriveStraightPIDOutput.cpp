#include "DriveStraightPIDOutput.h"
#include "WPILib.h"

DriveStraightPIDOutput::DriveStraightPIDOutput(RobotDrive *drive, RobotModel* robot) {
    this->drive = drive;
    this->robot = robot;
}

//Override
void DriveStraightPIDOutput::PIDWrite(double output) {
    double error = robot->rightDriveEncoder->GetDistance() - robot->leftDriveEncoder->GetDistance();
    drive->ArcadeDrive(output, error, false);
}
