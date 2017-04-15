/*
 * GearController.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: kidco
 */

#include "GearController.h"
#include "Params.h"

GearController::GearController(RobotModel* robot, RemoteControl* humanControl) {
	this->robot = robot;
	this->humanControl = humanControl;
	robot->gearPot->SetPIDSourceType(PIDSourceType::kDisplacement);
	gearTilterPIDOutput = new AnalogPIDOutput(robot);
	gearTilterPID = new PIDController(0.0, 0.0, 0.0, robot->gearPot,
			gearTilterPIDOutput);
	gearTilterPID->SetInputRange(-1.0, 1.0);
	gearTilterPID->SetOutputRange(-GEAR_TILTER_MAX_MOTOR_SPEED,
			GEAR_TILTER_MAX_MOTOR_SPEED);
	gearTilterPID->SetAbsoluteTolerance(0.01);
	gearTilterPID->SetPID(0.0, 0.0, 0.0);
	gearTilterPID->SetSetpoint(GEAR_POT_UP_POSITION);
	gearTilterPID->Disable();
	wasRest = false;
	wasRamp = false;
	wasRest = true;
	toggleManual = false;
	wasUp = false;
	m_stateVal = kInitialize;
	nextState = kInitialize;
}

void GearController::Reset() {
	//robot->pini->getf("GEAR_PID", "gear_p", 0.0);
	//robot->pini->getf("GEAR_PID", "gear_i" );
	//robot->pini->getf("GEAR_PID", "gear_d" );
	m_stateVal = kInitialize;
}

void GearController::Update() {
	switch (m_stateVal) {
	case (kInitialize):
		gearTilterPID->Disable();
		wasDown = false;
		wasRest = true;
		wasRamp = false;
		wasUp = false;
		gearTilterPID->SetPID(gear_p, gear_i, gear_d);
		gearTilterPID->SetOutputRange(-0.7, 0.7);
		gearTilterPID->SetSetpoint(GEAR_POT_UP_POSITION);
		toggleManual = false;
		nextState = kTeleop;
		break;
	case (kTeleop):
		if (humanControl->GetManualGearDesired()) {
			toggleManual = !toggleManual;
		}

		//Pot Mode
		if (toggleManual == false) {
			if (humanControl->GetGearTitlerDownDesired()) {
				GearDown();
			} else if (humanControl->GetGearTilterUpDesired()) {
				GearPIDUp();
			} else if (humanControl->GetGearTilterRampDesired()) {
				GearPIDRamp();
			} else {
				GearRest();
			}

			if (humanControl->GetGearTitlerIntakeDesired()) {
				robot->SetGearIntakeSpeed(GEAR_WHEELS_ACTIVE_MOTOR_SPEED);
			} else if (humanControl->GetGearTilterRampDesired()) {
				robot->SetGearIntakeSpeed(GEAR_WHEELS_ACTIVE_MOTOR_SPEED);
			} else if (humanControl->GetGearTitlerOuttakeDesired()) {
				robot->SetGearIntakeSpeed(-GEAR_WHEELS_ACTIVE_MOTOR_SPEED);
			} else {
				robot->SetGearIntakeSpeed(GEAR_WHEELS_RESTING_MOTOR_SPEED);
			}
		}

		//Manual Mode
		else {
			SoftDisablePID();
			if (fabs(
					humanControl->GetJoystickValue(RemoteControl::kOperatorJoy,
							RemoteControl::kLY)) < 0.1) {
				robot->SetGearTilterSpeed(0.0);
			} else {
				robot->SetGearTilterSpeed(
						humanControl->GetJoystickValue(
								RemoteControl::kOperatorJoy, RemoteControl::kLY)
								* 0.65);
			}
			if (humanControl->GetGearTitlerIntakeDesired()) {
				robot->SetGearIntakeSpeed(GEAR_WHEELS_ACTIVE_MOTOR_SPEED);
			} else if (humanControl->GetGearTitlerOuttakeDesired()) {
				robot->SetGearIntakeSpeed(-GEAR_WHEELS_ACTIVE_MOTOR_SPEED);
			} else {
				robot->SetGearIntakeSpeed(GEAR_WHEELS_RESTING_MOTOR_SPEED);
			}
		}

		nextState = kTeleop;
		break;
	}  // end of switch

	m_stateVal = nextState;
}

void GearController::GearPIDUp() {
	if (wasDown) {
		gearTilterPID->Reset();
	}
	wasDown = false;
	wasRamp = false;
	wasRest = false;
	wasUp = true;
	gearTilterPID->SetPID(gear_p, gear_i, gear_d);
	gearTilterPID->SetSetpoint(GEAR_POT_UP_POSITION);
	gearTilterPID->SetOutputRange(-0.65, 0.65);
	gearTilterPID->Enable();
	SmartDashboard::PutString("GEAR_STATE", "PID:UP");
}

void GearController::GearDown() {
	wasDown = true;
	wasRamp = false;
	wasRest = false;
	wasUp = false;
	SoftDisablePID();
	if (robot->gearPot->Get() <= GEAR_POT_FORCE_DOWN_THRESHOLD) {
		robot->SetGearTilterSpeed(0.25);
	} else {
		robot->SetGearTilterSpeed(0.0);
	}
	SmartDashboard::PutString("GEAR_STATE", "Down");
}

void GearController::GearPIDRamp() {
	wasDown = false;
	wasUp = false;
	wasRest = false;
	wasRamp = true;
	gearTilterPID->SetPID(gear_ramp_p, gear_ramp_i, gear_ramp_d);
	gearTilterPID->SetSetpoint(GEAR_POT_RAMP_POSITION);
	gearTilterPID->SetOutputRange(-0.4, 0.4);
	gearTilterPID->Enable();
	SmartDashboard::PutString("GEAR_STATE", "PID:ramp");
}

void GearController::GearRest() {
	wasDown = false;
	wasRamp = false;
	wasUp = false;
	wasRest = true;
	SoftDisablePID();
	if (robot->gearPot->Get() >= GEAR_POT_FORCE_REST_THRESHOLD) {
		robot->SetGearTilterSpeed(-0.3);
	} else {
		robot->SetGearTilterSpeed(0.0);
	}
	SmartDashboard::PutString("GEAR_STATE", "Rest");
}

void GearController::SoftDisablePID() {
	if (gearTilterPID->IsEnabled()) {
		gearTilterPID->Disable();
	}
}

GearController::~GearController() {
	// TODO Auto-generated destructor stub
}

