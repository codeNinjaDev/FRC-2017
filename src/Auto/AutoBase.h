/*
 * AutoBase.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTOBASE_H_
#define SRC_AUTO_AUTOBASE_H_
#include "Action/Action.h"
#include "WPILib.h"
#include <iostream>
using namespace std;

class AutoBase {
public:

  bool m_active = false;
  virtual void Prestart();
  void Run();
  void Stop();
  bool IsActive();
  static constexpr double m_update_rate = (1.0/50.0);

  //bool isActiveWithThrow() throw AutoRoutineEndedException;
  void RunAction(Action* action); /*throw AutoRoutineEndedException*/

protected:
  virtual void Routine();
  //virtual void routine();

};

#endif /* SRC_AUTO_AUTOBASE_H_ */
