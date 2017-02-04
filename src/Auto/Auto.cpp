/*
 * Auto.cpp

 *
 *  Created on: Jan 28, 2017
 *      Author: peter
 */
#include "Timer.h"

#include "Auto.h"

Auto::Auto() {
	selector = (AutonomousRoutinePicker*) (new AutonomousRoutinePicker());
	autoRoutineRunner = (AutoRoutineSetter*) (new AutoRoutineSetter());
	autoRoutine = (AutoRoutine *)(new  AutoRoutine());
}


void Auto::ListOptions() {
  selector->ListOptions();
}

void Auto::Start() {
  //Get the dashboard selection and set the auto routine
  autoRoutine = selector->Pick();
  autoRoutineRunner->setAutoRoutine(autoRoutine);

  //run the prestart for the function
  autoRoutine->Prestart();

  //Run the set autoroutine
  autoRoutineRunner->Start();

  //stop(); //!! Check if this is necessary!!
}

void Auto::Stop() {
  autoRoutineRunner->Stop();
}

Auto::~Auto() {
  // TODO Auto-generated destructor stub
}

