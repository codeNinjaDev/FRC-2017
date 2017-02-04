/*
 * AutonomousRoutinePicker->cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "AutonomousRoutinePicker.h"
#include "Commands/Command.h"



AutonomousRoutinePicker::AutonomousRoutinePicker() {
  RegisterAutonomous(new DoNothingRoutine());
  RegisterAutonomous(new DriveForwardRoutine());
  RegisterAutonomous(new JustShoot());
}

void AutonomousRoutinePicker::ListOptions() {
  autoChooser->AddDefault("Do nothing (Default)", "0");
  autoChooser->AddObject("Drive Forward 3s", "1");
  autoChooser->AddObject("Just Shoot (5s)", "2");
  SmartDashboard::PutData("Autonomous Selector", autoChooser);
}

AutoRoutine* AutonomousRoutinePicker::Pick() {
	std::string selected = autoChooser->GetSelected();
	int input = stoi(selected);
	SetAutoRoutineByIndex(input);

  return GetAutoRoutine();
}

void AutonomousRoutinePicker::RegisterAutonomous(AutoRoutine* autonomous) {
  autoRoutines->push_back(*autonomous);

}

AutoRoutine* AutonomousRoutinePicker::GetAutoRoutine() {
  return &(autoRoutines->at(selectedIndex));
}

void AutonomousRoutinePicker::SetAutoRoutineByIndex(int input) {
  if (input < 0 || input >= (int)autoRoutines->size()) {
    input = 0;
  }
  selectedIndex = input;
}

AutonomousRoutinePicker::~AutonomousRoutinePicker() {
  // TODO Auto-generated destructor stub
}

