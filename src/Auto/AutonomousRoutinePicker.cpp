/*
 * AutonomousRoutinePicker->cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "AutonomousRoutinePicker.h"

AutonomousRoutinePicker::AutonomousRoutinePicker() {

  RegisterAutonomous(new DoNothingRoutine());
  RegisterAutonomous(new DriveForwardRoutine());
  RegisterAutonomous(new JustShoot());

}

void AutonomousRoutinePicker::ListOptions() {

  autoChooser->AddDefault("Do nothing (Default)", 0);
  SmartDashboard::PutData("Autonomous Selector", autoChooser);

  autoChooser->AddObject("Drive", 1);
}

AutoRoutine* AutonomousRoutinePicker::Pick() {
  SmartDashboard::PutNumber("AutoChooser Value", autoChooser->GetSelected());
  SetAutoRoutineByIndex(autoChooser->GetSelected());

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

