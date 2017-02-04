/*
 * AutoBase.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#include "AutoBase.h"

AutoBase::AutoBase(){
	m_active = false;
}

void AutoBase::Run() {
  m_active = true;
  /*try {
    routine();
  }*/
  Routine();

  cout << "Auto mode on" << endl;
}

void AutoBase::Stop() {
  m_active = false;
}

bool AutoBase::IsActive() {
  return m_active;
}

void AutoBase::RunAction(Action* action) {
  action->Start();
  while (IsActive() && !action->IsFinished()) {
    action->Update();
  }

  action->Done();
}

AutoBase::~AutoBase() {
  // TODO Auto-generated destructor stub
}

