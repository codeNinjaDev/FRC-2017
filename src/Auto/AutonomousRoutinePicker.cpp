/*
 * AutonomousRoutinePicker.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "AutonomousRoutinePicker.h"

AutonomousRoutinePicker::AutonomousRoutinePicker() {

	RegisterAutonomous(new DoNothingRoutine());
	RegisterAutonomous(new DriveForwardRoutine());


}

void AutonomousRoutinePicker::ListOptions() {

	autoChooser.AddDefault("Do nothing (Default)", 0);
	autoChooser.AddObject("Drive Forward 3s", 1);

	SmartDashboard::PutData("Autonomous Selector", &autoChooser);

	//autoChooser.AddObject("Do nothing (Default)", 0);
}

AutoRoutine* AutonomousRoutinePicker::Pick() {
	SmartDashboard::PutNumber("AutoChooser Value", (unsigned int)autoChooser.GetSelected());

	SetAutoRoutineByIndex((int)autoChooser.GetSelected());

	return GetAutoRoutine();
}

void AutonomousRoutinePicker::RegisterAutonomous(AutoRoutine* autonomous) {
	autoRoutines->push_back(*autonomous);

}


AutoRoutine* AutonomousRoutinePicker::GetAutoRoutine() {
	return &(autoRoutines->at(selectedIndex));
}

void AutonomousRoutinePicker::SetAutoRoutineByIndex(unsigned int input) {
	if (input < 0 || input >= autoRoutines->size()) {
		input = 0;
	}
	    selectedIndex = input;
	}

AutonomousRoutinePicker::~AutonomousRoutinePicker() {
	// TODO Auto-generated destructor stub
}

