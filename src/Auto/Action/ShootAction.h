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
	double goal_time;
	double start_time;
	double speed;

	public:
	  ShootAction(double, double);
	  bool IsFinished();
	  void Update();
	  void Done();
	  void Start();
	  virtual ~ShootAction();
};

#endif /* SRC_AUTO_ACTION_SHOOTACTION_H_ */
