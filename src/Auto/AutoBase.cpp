/*
 * AutoBase.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#include <Auto/AutoBase.h>

void AutoBase::run() {
  m_active = true;
  /*try {
    routine();
  }*/
  routine();

  cout << "Auto mode on" << endl;

}

void AutoBase::stop() {
  m_active = false;
}

bool AutoBase::isActive() {
  return m_active;
}

void AutoBase::runAction(Action action) {
  isActive();
  action.start();
  while (isActive() && !action.isFinished()) {
    action.update();

  }
}

AutoBase::~AutoBase() {
  // TODO Auto-generated destructor stub
}

