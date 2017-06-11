/*
 * DriveSetPoint.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "DriveSetPointStraightAction.h"
#include "WPILib.h"
#include "../../Params.h"

//distance: distance in inches for the bot to drive
//maxSpeed: max speed robot can drive to hit setpoint
//timeout: amount of allowed time this action can run before ending
DriveSetPointStraightAction::DriveSetPointStraightAction(MasterController* controllers, double distance, double maxSpeed, double timeout, bool waitForTimeout, bool ejectGear) {
	this->driveController = controllers->GetDriveController();
	this->distance = distance;
	this->timeout = timeout;
	this->robot = controllers->GetRobotModel();
	this->maxSpeed = maxSpeed;
	this->waitForTimeout = waitForTimeout;
	this->lights = controllers->GetLightsController();
	this->gearController = controllers->GetGearController();
	this->ejectGear = ejectGear;
	reachedSetpoint = false;
	target_pass = 0;
	leftEncoderStartDistance, rightEncoderStartDistance = 0.0;

	P = drive_p;
	I = drive_i;
	D = drive_d;
}

bool DriveSetPointStraightAction::IsFinished() {
	if((Timer::GetFPGATimestamp() >= start_time + timeout) && !(reachedSetpoint)) {
	}
    if(waitForTimeout)
        return (Timer::GetFPGATimestamp() >= start_time + timeout);
	else
        return (Timer::GetFPGATimestamp() >= start_time + timeout) || reachedSetpoint;

}

void DriveSetPointStraightAction::Update() {
	if (driveController->leftPID->OnTarget() && driveController->rightPID->OnTarget()) {
		reachedSetpoint = true;
	} else {
		reachedSetpoint = false;
	}

	if(ejectGear)
		robot->SetGearIntakeSpeed(-GEAR_WHEELS_OUT_MOTOR_SPEED);

}

void DriveSetPointStraightAction::Done() {
	driveController->leftPID->Disable();
	driveController->rightPID->Disable();
	robot->SetGearIntakeSpeed(0.0);
	driveController->Stop();
}

void DriveSetPointStraightAction::Start() {
	start_time = Timer::GetFPGATimestamp();

	robot->leftDriveEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
	robot->rightDriveEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);

	robot->leftDriveEncoder->Reset();
	robot->rightDriveEncoder->Reset();

	leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
	rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();

	driveController->leftPID->SetOutputRange(-maxSpeed, maxSpeed);
	driveController->leftPID->SetPID(P, I, D);
	driveController->leftPID->SetSetpoint(distance);


	driveController->rightPID->SetOutputRange(-maxSpeed, maxSpeed);
	driveController->rightPID->SetPID(P, I, D);
	driveController->rightPID->SetSetpoint(distance);

	driveController->leftPID->Enable();
	driveController->rightPID->Enable();
}
