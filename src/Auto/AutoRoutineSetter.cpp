/*
 * AutoRoutineSetter.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: peter
 */

#include "AutoRoutineSetter.h"

static Timer* autoTimer = new Timer();


void AutoRoutineSetter::setAutoRoutine(AutoRoutine* new_auto_routine) {

  m_auto_routine = new_auto_routine;

}

void AutoRoutineSetter::Start() {
  if(m_auto_routine != nullptr) {
    m_auto_routine->Run();
  }
  autoTimer->Start();
}

void AutoRoutineSetter::Stop() {
  if(m_auto_routine != nullptr) {
    m_auto_routine->Stop();
  }
  autoTimer->Stop();
}

AutoRoutineSetter::~AutoRoutineSetter() {
  // TODO Auto-generated destructor stub
}

