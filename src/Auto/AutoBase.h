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
  virtual void prestart();
  void run();
  void stop();
  bool isActive();
  //bool isActiveWithThrow() throw AutoRoutineEndedException;
  void runAction(Action action); /*throw AutoRoutineEndedException*/

  AutoBase();
  virtual ~AutoBase();
protected:
  virtual void routine();
  static const double m_update_rate = (1.0/50.0);
  //virtual void routine();

};

#endif /* SRC_AUTO_AUTOBASE_H_ */
