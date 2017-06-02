/*
 * VisionSetpointXAction.h
 *
 *  Created on: Mar 10, 2017
 *      Author: michael
 */

#ifndef SRC_AUTO_ACTION_VISIONSETPOINTXACTION_H_
#define SRC_AUTO_ACTION_VISIONSETPOINTXACTION_H_
#include "../../Controllers/LightsController.h"
#include "Timer.h"
#include "Action.h"
#include "../../Controllers/DriveController.h"
#include "../../Controllers/VisionController.h"

class VisionSetpointXAction: public Action {
public:
	VisionSetpointXAction(MasterController* controllers, int setpoint, double maxSpeed, double timeout, bool waitForTimeout);

	bool IsFinished();
	void Update();
	void Done();
	void Start();

	virtual ~VisionSetpointXAction();

private:

	double P, I, D;
	bool waitForTimeout;
	int setpoint;
	double maxSpeed, timeout;
	double leftEncoderStartDistance, rightEncoderStartDistance;
	VisionController *vision;
	DriveController *driveController;
	RobotModel *robot;
	LightsController* lights;
};

#endif /* SRC_AUTO_ACTION_VISIONSETPOINTXACTION_H_ */
