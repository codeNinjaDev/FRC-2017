/*
 * DriveSetPoint.h
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ACTION_ARCADEDRIVESTRAIGHTACTION_H_
#define SRC_AUTO_ACTION_ARCADEDRIVESTRAIGHTACTION_H_
#include "LightsController.h"
#include "../../RobotModel.h"
#include "../../DriveController.h"
#include "WPILib.h"
#include "Action.h"
#include "Params.h"
#include "GearController.h"
class ArcadeDriveStraightAction: public Action {
public:
	ArcadeDriveStraightAction(RobotModel *robot, DriveController *driveController,
	                          GearController *gearController, double distance, double maxSpeed,
	                          double timeout, bool waitForTimeout, LightsController* lights,
	                          bool ejectGear);
	bool IsFinished();
	void Update();
	void Done();
	void Start();

private:
	DriveController *driveController;
	RobotModel *robot;
	LightsController* lights;
	GearController* gearController;

	bool reachedSetpoint, waitForTimeout, ejectGear;

	double distance, maxSpeed, timeout;

	double P, I, D;

	double leftEncoderStartDistance, rightEncoderStartDistance;
};

#endif /* SRC_AUTO_ACTION_DRIVESETPOINT_H_ */
