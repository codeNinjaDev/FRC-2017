/*
 * AutoRoutine.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTOROUTINE_H_
#define SRC_AUTO_AUTOROUTINE_H_

#include "WPILib.h"
#include <iostream>
#include "Action/Action.h"
#include "Action/DriveIntervalAction.h"
#include "Action/ShootAction.h"


class AutoRoutine {
public:
  bool m_active = false;
  virtual void Prestart();
  void Run();
  void Stop();
  bool IsActive();
  static constexpr double m_update_rate = (1.0/50.0);

  //bool isActiveWithThrow() throw AutoRoutineEndedException;
  void RunAction(Action* action);
  void DriveInterval(double seconds, double y, double x);
  void Shoot(double seconds, double speed);
protected:
  virtual void Routine();
  //virtual void routine();

};

#endif /* SRC_AUTO_AUTOROUTINE_H_ */
