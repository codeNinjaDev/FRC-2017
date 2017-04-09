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
#include "../../Profile.h"
#include "../../DriveController.h"
class DriveIntervalAction: public Action {
public:
	DriveIntervalAction(Profile* profile, double timeout, double distance);

	bool IsFinished();
	void Update();
	void Done();
	void Start();

	virtual ~DriveIntervalAction();

private:
	Profile* profile;
	double distance;

};

#endif /* SRC_AUTO_ACTION_DRIVEINTERVALACTION_H_ */
