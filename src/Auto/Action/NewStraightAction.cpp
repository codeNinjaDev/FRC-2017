/*
 * NewStraight.cpp
 *
 *  Created on: April 15, 2017
 *      Author: mikechacko
 */

#include "NewStraightAction.h"
#include "WPILib.h"
#include "../../Params.h"

//distance: distance in inches for the bot to drive
//maxSpeed: max speed robot can drive to hit setpoint
//timeout: amount of allowed time this action can run before ending.
NewStraightAction::NewStraightAction(MasterController* controllers,
		double distance, double maxSpeed, double timeout, double timeAfterHit) {
	this->driveController = controllers->GetDriveController();
	this->timeout = timeout;
	this->robot = controllers->GetRobotModel();
	this->lights = controllers->GetLightsController();
	this->gearController = controllers->GetGearController();
    this->maxSpeed = maxSpeed;
    this->distance = distance;

	this->timeAfterHit = timeAfterHit;
	reachedSetpoint = false;
	target_pass = 0;
	leftEncoderStartDistance = 0.0;
	rightEncoderStartDistance = 0.0;

	P = new_drive_p;
	I = new_drive_i;
	D = new_drive_d;

}

bool NewStraightAction::IsFinished() {
    return (Timer::GetFPGATimestamp() >= start_time + timeout);
}

void NewStraightAction::Update() {

}

void NewStraightAction::Done() {
	driveController->newPIDstraight->Disable();
}

void NewStraightAction::Start() {
	start_time = Timer::GetFPGATimestamp();

	robot->leftDriveEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
	robot->rightDriveEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);

	robot->leftDriveEncoder->Reset();
	robot->rightDriveEncoder->Reset();

	leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
	rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();

	driveController->newPIDstraight->SetOutputRange(-maxSpeed, maxSpeed);
	driveController->newPIDstraight->SetPID(P, I, D);
	driveController->newPIDstraight->SetSetpoint(distance);

	driveController->newPIDstraight->Enable();
}
