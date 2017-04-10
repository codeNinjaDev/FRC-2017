/*
 * AutonomousRoutinePicker->cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "AutoSelector.h"

AutoSelector::AutoSelector(MasterController* controller) {

  autoRoutines = new vector<AutoRoutine*>();
  RegisterAutonomous(new DoNothingRoutine());
  RegisterAutonomous(new DriveForwardRoutine(controller));
  RegisterAutonomous(new CenterGear(controller));
  RegisterAutonomous(new LeftGear(controller));
  RegisterAutonomous(new RightGear(controller));
  RegisterAutonomous(new PassAutoLine(controller));
  RegisterAutonomous(new BoilerFirstHopper(controller));
  RegisterAutonomous(new Blank1(controller));
  RegisterAutonomous(new Blank2(controller));
  RegisterAutonomous(new Blank3(controller));

  autoChooser = new AutoWidget();
}

void AutoSelector::ListOptions() {
  autoChooser->AddDefault("Do nothing (Default)", 0);
  autoChooser->AddObject("Drive (1s)", 1);
  autoChooser->AddObject("CenterField Gear", 2);
  autoChooser->AddObject("LeftField Gear", 3);
  autoChooser->AddObject("RightField Gear", 4);
  autoChooser->AddObject("Pass AutoLine", 5);
  autoChooser->AddObject("Left Hopper", 6);
  autoChooser->AddObject("Blank 1", 7);
  autoChooser->AddObject("Blank 2", 8);
  autoChooser->AddObject("Blank 3", 9);


  SmartDashboard::PutData("Autonomous: ", autoChooser);

}

AutoRoutine* AutoSelector::Pick() {
	SetAutoRoutineByIndex(autoChooser->GetSelected());
	return GetAutoRoutine();
}

void AutoSelector::RegisterAutonomous(AutoRoutine* autonomous) {
	autoRoutines->push_back(autonomous);
}

AutoRoutine* AutoSelector::GetAutoRoutine() {
	return autoRoutines->at(selectedIndex);
}

void AutoSelector::SetAutoRoutineByIndex(int input) {
	if (input < 0 || input >= autoRoutines->size()) {
		input = 0;
	}
	selectedIndex = input;
}

AutoRoutine* AutoSelector::GetDefaultRoutine() {
	return autoRoutines->at(0);
}

AutoSelector::~AutoSelector() {
}

