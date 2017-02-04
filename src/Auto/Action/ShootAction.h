/*
 * ShootAction.h
 *
 *  Created on: Jan 30, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ACTION_SHOOTACTION_H_
#define SRC_AUTO_ACTION_SHOOTACTION_H_
#include "Action.h"
#include "Timer.h"
class ShootAction: public Action {
public:
  ShootAction(double seconds, double speed);
  bool IsFinished();
  void Update();
  void Done();
  void Start();
  ~ShootAction();
protected:

};

#endif /* SRC_AUTO_ACTION_SHOOTACTION_H_ */
