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

	autoChooser->AddDefault("Do nothing (Default)", 0);
	autoChooser->AddObject("Drive Forward 3s", 1);

	SmartDashboard::PutData("Autonomous Selector", autoChooser);

	//autoChooser.AddObject("Do nothing (Default)", 0);
}

AutoRoutine* AutonomousRoutinePicker::Pick() {
	if(autoChooser->GetSelected()) {
      SmartDashboard::PutNumber("AutoChooser Value", (int) autoChooser->GetSelected());
	  SetAutoRoutineByIndex((int)autoChooser->GetSelected());
	} else {
	  SmartDashboard::PutNumber("AutoChooser Value", 0);
	  SetAutoRoutineByIndex(0);

	}

	return GetAutoRoutine();
}

void AutonomousRoutinePicker::RegisterAutonomous(AutoRoutine* autonomous) {
	autoRoutines->push_back(*autonomous);

}


AutoRoutine* AutonomousRoutinePicker::GetAutoRoutine() {
	return &(autoRoutines->at(selectedIndex));
}

void AutonomousRoutinePicker::SetAutoRoutineByIndex(int input) {
	if (input < 0 || input >= autoRoutines->size()) {
		input = 0;
	}
	    selectedIndex = input;
	}

AutonomousRoutinePicker::~AutonomousRoutinePicker() {
	// TODO Auto-generated destructor stub
}

