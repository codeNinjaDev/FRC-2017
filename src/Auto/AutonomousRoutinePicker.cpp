/*
 * AutonomousRoutinePicker.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include <Auto/AutonomousRoutinePicker.h>

AutonomousRoutinePicker::AutonomousRoutinePicker() {

	registerAutonomous(new DoNothingRoutine());
	registerAutonomous(new DriveForwardRoutine());


}

void AutonomousRoutinePicker::listOptions() {

	autoChooser.AddDefault("Do nothing (Default)", 0);
	autoChooser.AddObject("Drive Forward 3s", 1);

	SmartDashboard::PutData("Autonomous Selector", &autoChooser);

	//autoChooser.AddObject("Do nothing (Default)", 0);
}

AutoRoutine* AutonomousRoutinePicker::pick() {
	SmartDashboard::PutNumber("AutoChooser Value", (int)autoChooser.GetSelected());

	setAutoRoutineByIndex((int)autoChooser.GetSelected());

	return getAutoRoutine();
}

void AutonomousRoutinePicker::registerAutonomous(AutoRoutine* autonomous) {
	autoRoutines->push_back(*autonomous);

}


AutoRoutine* AutonomousRoutinePicker::getAutoRoutine() {
	return &(autoRoutines->at(selectedIndex));
}

void AutonomousRoutinePicker::setAutoRoutineByIndex(int input) {
	if (input < 0 || input >= autoRoutines->size()) {
		input = 0;
	}
	    selectedIndex = input;
	}

AutonomousRoutinePicker::~AutonomousRoutinePicker() {
	// TODO Auto-generated destructor stub
}

