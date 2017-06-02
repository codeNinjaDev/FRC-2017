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
#include "../../Controllers/DriveController.h"
#include "../../MasterController.h"

class DriveIntervalAction: public Action {
public:
	DriveIntervalAction(MasterController* kDrive, double seconds, double y,double x);

	bool IsFinished();
	void Update();
	void Done();
	void Start();

	virtual ~DriveIntervalAction();

private:
	DriveController* kDrive;
};

#endif /* SRC_AUTO_ACTION_DRIVEINTERVALACTION_H_ */
