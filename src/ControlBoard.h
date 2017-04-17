/*
 * ControlBoard.h
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#ifndef SRC_CONTROLBOARD_H_
#define SRC_CONTROLBOARD_H_

#include "WPILib.h"
#include "ButtonReader.h"
#include "TriggerReader.h"
#include "RemoteControl.h"

class ControlBoard: public RemoteControl {
public:
	ControlBoard();
	~ControlBoard() {
	};

	virtual void ReadControls();

	//Drive joystick accessors
	double GetJoystickValue(Joysticks j, Axes a);

	bool GetReverseDriveDesired();
	bool GetArcadeDriveDesired();
	bool GetClimberLockDesired();
	bool GetSlowDriveTier1Desired();
	bool GetSlowDriveTier2Desired();
	bool GetDriveBackDesired();
	bool GetDriveBackOtherDesired();
	bool GetGearTitlerDownDesired();
	bool GetGearTilterUpDesired();
	bool GetGearTilterRampDesired();
	bool GetGearTitlerOuttakeDesired();
	bool GetGearTitlerIntakeDesired();
	bool GetManualGearDesired();
	ButtonReader *driveDirectionButton, *driveBackButton, *driveBackOtherButton,
		*gearTilterOuttakeButton, *gearTilterIntakeButton, *toggleDisabledGearTilter, *toggleGearManual, *gearTilterRampButton;

	TriggerReader *slowDriveTier1Button, *slowDriveTier2Button, *gearTilterDownButton, *gearTilterUpButton;

private:

	//booleans for desired states of robot

	bool reverseDriveDesired, arcadeDriveDesired, slowDriveTier1Desired, slowDriveTier2Desired,
		driveBackDesired, driveBackOtherDesired, gearTilterDownDesired, gearTilterOuttakeDesired, gearTilterIntakeDesired,
		toggleDisabledGearTilterDesired, toggleGearManualDesired, gearTilterRampDesired, gearTilterUpDesired;

	double driverLeftJoyX, driverLeftJoyY, driverRightJoyX, driverRightJoyY;
	double operatorLeftJoyX, operatorLeftJoyY, operatorRightJoyX, operatorRightJoyY;

	Joystick *driverJoy, *operatorJoy;



	void ReadAllButtons();
};

#endif /* SRC_CONTROLBOARD_H_ */
