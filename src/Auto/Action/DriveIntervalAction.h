/*
 * DriveInterval.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ACTION_DRIVEINTERVALACTION_H_
#define SRC_AUTO_ACTION_DRIVEINTERVALACTION_H_

#include "Timer.h"
#include "Action.h"

class DriveIntervalAction : public Action {
	double goal_time;
	double start_time;
	double x_drive;
	double y_drive;

	public:
	  DriveIntervalAction(double, double, double);
	  bool IsFinished();
	  void Update();
	  void Done();
	  void Start();
	  virtual ~DriveIntervalAction();
};

#endif /* SRC_AUTO_ACTION_DRIVEINTERVALACTION_H_ */
