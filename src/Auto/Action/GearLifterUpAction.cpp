
#include "GearLifterUpAction.h"
#include "../../Params.h"
#include <Timer.h>

//distance: distance in inches for the bot to drive
//maxSpeed: max speed robot can drive to hit setpoint
//timeout: amount of allowed time this action can run before ending
GearLifterUpAction::GearLifterUpAction(MasterController* controllers,
		double distance, double maxSpeed, double timeout, bool waitForTimeout) {
	this->driveController = controllers->GetDriveController();
	this->gearController = controllers->GetGearController();
	this->distance = distance;
	this->timeout = timeout;
	this->robot = controllers->GetRobotModel();
	this->maxSpeed = maxSpeed;
	this->waitForTimeout = waitForTimeout;
	reachedSetpoint = false;
	target_pass = 0;
	leftEncoderStartDistance, rightEncoderStartDistance = 0.0;

	P = robot->pini->getf("DRIVE_PID", "drive_p", 0.0);
	I = robot->pini->getf("DRIVE_PID", "drive_i", 0.0);
	D = robot->pini->getf("DRIVE_PID", "drive_d", 0.0);
}

bool GearLifterUpAction::IsFinished() {
	if(waitForTimeout)
        return (Timer::GetFPGATimestamp() >= start_time + timeout);
	else
        return (Timer::GetFPGATimestamp() >= start_time + timeout) || reachedSetpoint;

}

void GearLifterUpAction::Update() {
	if (driveController->leftPID->OnTarget() && driveController->rightPID->OnTarget()) {
		reachedSetpoint = true;
	} else {
		reachedSetpoint = false;
	}
	SmartDashboard::PutBoolean("ACTION_DriveSetpointStraight", true);
}

void GearLifterUpAction::Done() {
	driveController->leftPID->Disable();
	driveController->rightPID->Disable();
	gearController->gearTilterPID->Disable();
	SmartDashboard::PutBoolean("ACTION_DriveSetpointStraight", false);
	driveController->Stop();
}

void GearLifterUpAction::Start() {
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
	driveController->rightPID->SetSetpoint(
			distance + rightEncoderStartDistance);

	driveController->leftPID->Enable();
	driveController->rightPID->Enable();

	gearController->gearTilterPID->SetPID(
	        				robot->pini->getf("GEAR_PID", "gear_p", 0.0),
							robot->pini->getf("GEAR_PID", "gear_i", 0.0),
							robot->pini->getf("GEAR_PID", "gear_d", 0.0),
							robot->pini->getf("GEAR_PID", "gear_f", 0.0));
	        		gearController->gearTilterPID->SetOutputRange(-1.0, 1.0);
	        		gearController->gearTilterPID->SetSetpoint(GEAR_POT_UP_POSITION);
	        		gearController->gearTilterPID->Enable();
}
