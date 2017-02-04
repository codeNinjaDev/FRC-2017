/*
 * AutoRoutine.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#include "AutoRoutine.h"
/*void AutoRoutine::WaitTime(double seconds) {
  AutoRoutine::runAction(new TimeoutAction(seconds));
}*/

void AutoRoutine::Run() {
  m_active = true;
  /*try {
    routine();
  }*/
  Routine();



}

void AutoRoutine::Stop() {
  m_active = false;
}

bool AutoRoutine::IsActive() {
  return m_active;
}

void AutoRoutine::RunAction(Action* action) {
  action->Start();
  while (IsActive() && !action->IsFinished()) {
    action->Update();

  }

  action->Done();
}

void AutoRoutine::DriveInterval(double seconds, double y, double x) {

  RunAction(new DriveIntervalAction(seconds, y, x));
}

void AutoRoutine::Shoot(double seconds, double speed) {
  RunAction(new ShootAction(seconds, speed));
}


