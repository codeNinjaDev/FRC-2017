/*
 * DriveSetPoint.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "DriveSetPointRotateAction.h"
#include "WPILib.h"
//distance: distance in inches for the bot to rotate
//maxSpeed: max speed robot can drive to hit setpoint
//timeout: amount of allowed time this action can run before ending
DriveSetPointRotateAction::DriveSetPointRotateAction(MasterController* controllers, double angle, double maxSpeed, double timeout, bool waitForTimeout) {
	this->driveController = controllers->GetDriveController();
	this->distance = (angle * 40.0) / (180.0);
	this->timeout = timeout;
	this->robot = controllers->GetRobotModel();
	this->maxSpeed = maxSpeed;
    this->waitForTimeout = waitForTimeout;
    this->lights = controllers->GetLightsController();
	reachedSetpoint = false;
	leftEncoderStartDistance, rightEncoderStartDistance = 0.0;

	P = 0.3;
	I = robot->pini->getf("DRIVE_PID", "drive_i", 0.0);
	D = robot->pini->getf("DRIVE_PID", "drive_d", 0.0);
	SmartDashboard::PutNumber("DRIVE_PID_P", P);
	SmartDashboard::PutNumber("DRIVE_PID_I", I);
	SmartDashboard::PutNumber("DRIVE_PID_D", D);
}

bool DriveSetPointRotateAction::IsFinished() {
    if((Timer::GetFPGATimestamp() >= start_time + timeout) && !(reachedSetpoint)) {
    }
    if(waitForTimeout)
        return (Timer::GetFPGATimestamp() >= start_time + timeout);
	else
        return (Timer::GetFPGATimestamp() >= start_time + timeout) || reachedSetpoint;

}

void DriveSetPointRotateAction::Update() {
	if(driveController->leftPID->OnTarget() && driveController->rightPID->OnTarget()) {
		reachedSetpoint = true;
	}
	else {
		reachedSetpoint = false;
	}
}

void DriveSetPointRotateAction::Done() {
	driveController->leftPID->Disable();
	driveController->rightPID->Disable();
	driveController->Stop();
}

void DriveSetPointRotateAction::Start() {
	start_time = Timer::GetFPGATimestamp();

	robot->leftDriveEncoder->Reset();
	robot->rightDriveEncoder->Reset();

	leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
	rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();

	driveController->leftPID->SetOutputRange(-maxSpeed, maxSpeed);
	driveController->leftPID->SetPID(P, I, D);
	driveController->leftPID->SetSetpoint(distance + leftEncoderStartDistance);

	driveController->rightPID->SetOutputRange(-maxSpeed, maxSpeed);
	driveController->rightPID->SetPID(P, I, D);
	driveController->rightPID->SetSetpoint(-1.0 * (distance + rightEncoderStartDistance));

	driveController->leftPID->Enable();
	driveController->rightPID->Enable();
}
