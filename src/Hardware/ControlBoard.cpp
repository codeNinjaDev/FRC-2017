#include "WPILib.h"
#include "XInput.h"
#include "ControlBoard.h"
#include "Ports.h"
#include "Params.h"

//This file defines all the joysticks, buttons, other variables, and functions necessary
//to control the robot during teleop by getting human input from the driver station.

//Constructor defines all variables
ControlBoard::ControlBoard() {
	//Two Joysticks
	driverJoy = new Joystick(DRIVER_JOY_USB_PORT);
	operatorJoy = new Joystick(OPERATOR_JOY_USB_PORT);

	if (USING_WIN_DRIVER_STATION) {
		driveDirectionButton = new ButtonReader(driverJoy,
				XINPUT_WIN_START_BUTTON);
		slowDriveTier1Button = new TriggerReader(driverJoy,
				XINPUT_WIN_RIGHT_TRIGGER_AXIS);
		slowDriveTier2Button = new TriggerReader(driverJoy,
				XINPUT_WIN_LEFT_TRIGGER_AXIS);
		driveBackButton = new ButtonReader(driverJoy, XINPUT_WIN_BACK_BUTTON);
		driveBackOtherButton = new ButtonReader(driverJoy,
				XINPUT_WIN_LEFT_BUMPER);
		toggleDisabledGearTilter = new ButtonReader(driverJoy,
				XINPUT_WIN_LEFT_BUMPER);

		gearTilterIntakeButton = new ButtonReader(operatorJoy,
				XINPUT_WIN_GREEN_BUTTON);
		gearTilterOuttakeButton = new ButtonReader(operatorJoy,
				XINPUT_WIN_RED_BUTTON);
		toggleGearManual = new ButtonReader(operatorJoy,
				XINPUT_WIN_BACK_BUTTON);
		gearTilterDownButton = new TriggerReader(operatorJoy,
				XINPUT_WIN_RIGHT_TRIGGER_AXIS);
		gearTilterUpButton = new TriggerReader(operatorJoy,
				XINPUT_WIN_LEFT_TRIGGER_AXIS);
		gearTilterRampButton = new ButtonReader(operatorJoy,
				XINPUT_WIN_LEFT_BUMPER);
	}

	//Joystick positions that will set speed of robot movement
	driverLeftJoyX = 0;
	driverLeftJoyY = 0;
	driverRightJoyX = 0;
	driverRightJoyY = 0;

	//Drivetrain variables
	reverseDriveDesired = false;
	arcadeDriveDesired = USE_ARCADE_DRIVE;

	slowDriveTier1Desired = false;
	slowDriveTier2Desired = false;
	driveBackDesired = false;
	driveBackOtherDesired = false;
	gearTilterDownDesired = false;
	gearTilterUpDesired = false;
	gearTilterRampDesired = false;
	gearTilterOuttakeDesired = false;
	gearTilterIntakeDesired = false;
	toggleGearManualDesired = false;
}

//ReadControls reads the states of all the buttons and joysticks, and sets variables
//according to the values of the controls.
void ControlBoard::ReadControls() {
ReadAllButtons();

if (USING_WIN_DRIVER_STATION) {
	driverLeftJoyX = driverJoy->GetRawAxis(XINPUT_WIN_LEFT_X_AXIS);
	driverLeftJoyY = -driverJoy->GetRawAxis(XINPUT_WIN_LEFT_Y_AXIS);
	driverRightJoyX = driverJoy->GetRawAxis(XINPUT_WIN_RIGHT_X_AXIS);
	driverRightJoyY = -driverJoy->GetRawAxis(XINPUT_WIN_RIGHT_Y_AXIS);

	operatorLeftJoyX = operatorJoy->GetRawAxis(XINPUT_WIN_LEFT_X_AXIS);
	operatorLeftJoyY = -operatorJoy->GetRawAxis(XINPUT_WIN_LEFT_Y_AXIS);
	operatorRightJoyX = operatorJoy->GetRawAxis(XINPUT_WIN_RIGHT_X_AXIS);
	operatorRightJoyY = -operatorJoy->GetRawAxis(XINPUT_WIN_RIGHT_Y_AXIS);
}

//DriveTrain Variables
reverseDriveDesired = driveDirectionButton->IsDown();

//Superstructure Variables
slowDriveTier1Desired    = slowDriveTier1Button->IsDown();
 slowDriveTier2Desired    = slowDriveTier2Button->IsDown();
 driveBackDesired         = driveBackButton->IsDown();
 driveBackOtherDesired    = driveBackOtherButton->IsDown();
 gearTilterDownDesired    = gearTilterDownButton->IsDown();
 gearTilterUpDesired      = gearTilterUpButton->IsDown();
 gearTilterRampDesired    = gearTilterRampButton->IsDown();
 gearTilterOuttakeDesired = gearTilterOuttakeButton->IsDown();
 gearTilterIntakeDesired  = gearTilterIntakeButton->IsDown();
 toggleGearManualDesired  = toggleGearManual->WasJustPressed();

}

//Reads the values of all buttons defined by this class
void ControlBoard::ReadAllButtons() {
	driveDirectionButton->ReadValue();
	slowDriveTier1Button->ReadValue();
	slowDriveTier2Button->ReadValue();
	driveBackButton->ReadValue();
	driveBackOtherButton->ReadValue();
	gearTilterDownButton->ReadValue();
	gearTilterUpButton->ReadValue();
	gearTilterRampButton->ReadValue();
	gearTilterOuttakeButton->ReadValue();
	gearTilterIntakeButton->ReadValue();
	toggleGearManual->ReadValue();
}

//Returns the joystick and axis being used
double ControlBoard::GetJoystickValue(Joysticks j, Axes a) {
switch (j) {
case (kDriverJoy):
	if (a == kLX) {
		return driverLeftJoyX;
	} else if (a == kLY) {
		return driverLeftJoyY;
	} else if (a == kRX) {
		return driverRightJoyX;
	} else if (a == kRY) {
		return driverRightJoyY;
	}
	break;
case (kOperatorJoy):
	if (a == kLX) {
		return operatorLeftJoyX;
	} else if (a == kLY) {
		return operatorLeftJoyY;
	} else if (a == kRX) {
		return operatorRightJoyX;
	} else if (a == kRY) {
		return operatorRightJoyY;
	}
	break;
default:
	return 0.0;
	break;
}
return 0.0;
}

//Returns true if reverse drive is desired
bool ControlBoard::GetReverseDriveDesired() {
return reverseDriveDesired;
}

//Returns true if arcade drive is desired
bool ControlBoard::GetArcadeDriveDesired() {
return arcadeDriveDesired;
}

bool ControlBoard::GetSlowDriveTier1Desired() {
return slowDriveTier1Desired;
}

bool ControlBoard::GetSlowDriveTier2Desired() {
return slowDriveTier2Desired;
}

bool ControlBoard::GetDriveBackDesired() {
return driveBackDesired;
}

bool ControlBoard::GetDriveBackOtherDesired() {
return driveBackOtherDesired;
}

bool ControlBoard::GetGearTitlerDownDesired() {
return gearTilterDownDesired;
}
bool ControlBoard::GetGearTilterUpDesired() {
return gearTilterUpDesired;
}
bool ControlBoard::GetGearTilterRampDesired() {
return gearTilterRampDesired;
}

bool ControlBoard::GetGearTitlerIntakeDesired() {
return gearTilterIntakeDesired;
}

bool ControlBoard::GetGearTitlerOuttakeDesired() {
return gearTilterOuttakeDesired;
}
bool ControlBoard::GetManualGearDesired() {
return toggleGearManualDesired;
}
