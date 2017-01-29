/*
 * AutoRoutineSetter.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: peter
 */

#include "AutoRoutineSetter.h"


void AutoRoutineSetter::setAutoRoutine(AutoRoutine* new_auto_routine) {

  m_auto_routine = new_auto_routine;

}

void AutoRoutineSetter::Start() {
  if(m_auto_routine != nullptr) {
    m_auto_routine->Run();
  }
}

void AutoRoutineSetter::Stop() {
  if(m_auto_routine != nullptr) {
    m_auto_routine->Stop();
  }
}

AutoRoutineSetter::~AutoRoutineSetter() {
  // TODO Auto-generated destructor stub
}

