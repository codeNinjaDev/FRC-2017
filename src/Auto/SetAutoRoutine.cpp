/*
 * SetAutoRoutine.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: peter
 */

#include <Auto/SetAutoRoutine.h>

void SetAutoRoutine::setAutoRoutine(AutoRoutine* new_auto_routine) {

  m_auto_routine = new_auto_routine;

}

void SetAutoRoutine::start() {
  run();
}

void SetAutoRoutine::run() {
  if(m_auto_routine != nullptr) {
    m_auto_routine->run();
  }
}

void SetAutoRoutine::stop() {
  if(m_auto_routine != nullptr) {
    m_auto_routine->stop();
  }
}
SetAutoRoutine::~SetAutoRoutine() {
  // TODO Auto-generated destructor stub
}

