/*
 * Auto.cpp

 *
 *  Created on: Jan 28, 2017
 *      Author: peter
 */
#include "Timer.h"

static Timer* autoTimer = new Timer();
#include <Auto/Auto.h>
AutonomousRoutinePicker* selector = new AutonomousRoutinePicker();
  SetAutoRoutine* autoRoutineRunner = new SetAutoRoutine();
void Auto::listOptions() {
  selector->listOptions();
}

void Auto::start() {
  //Get the dashboard selection and set the auto routine
  autoRoutine = selector->pick();
  autoRoutineRunner->setAutoRoutine(autoRoutine);



  //run the prestart for the function
  autoRoutine->prestart();
  //Run the set autoroutine
  autoTimer->Start();
  autoRoutineRunner->start();
  //stop(); //!! Check if this is necessary!!
}

void Auto::stop() {
  autoRoutineRunner->stop();
}
Auto::~Auto() {
  // TODO Auto-generated destructor stub
}

