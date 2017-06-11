/*
 * DriveSetPoint.h
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ACTION_NEWSTRAIGHTACTION_H_
#define SRC_AUTO_ACTION_NEWSTRAIGHTACTION_H_

#include "../../Hardware/RobotModel.h"
#include "../../Controllers/DriveController.h"
#include "../../Controllers/GearController.h"
#include "../../Controllers/LightsController.h"
#include "WPILib.h"
#include "Action.h"

class NewStraightAction: public Action {
public:
	NewStraightAction(MasterController* controllers,
			double distance, double maxSpeed, double timeout, double timeAfterHit);
	bool IsFinished();
	void Update();
	void Done();
	void Start();

private:
	DriveController *driveController;
	RobotModel *robot;
	GearController *gearController;
	LightsController* lights;
	bool reachedSetpoint;

	double distance, maxSpeed, timeout, timeAfterHit;
	double afterSetpointTime;

	double P, I, D;
	int target_pass;
	double leftEncoderStartDistance, rightEncoderStartDistance;
};

#endif /* SRC_AUTO_ACTION_DRIVESETPOINT_H_ */
