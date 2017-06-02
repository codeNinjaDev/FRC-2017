
#ifndef SRC_AUTO_ACTION_GEAR_LIFTER_UP_ACTION_H_
#define SRC_AUTO_ACTION_GEAR_LIFTER_UP_ACTION_H_

#include "../../Hardware/RobotModel.h"
#include "../../Controllers/DriveController.h"
#include "../../Controllers/GearController.h"
#include "WPILib.h"
#include "Action.h"
class GearLifterUpAction: public Action {
public:
	GearLifterUpAction(MasterController* controllers,
			double distance, double maxSpeed, double timeout, bool waitForTimeout);
	bool IsFinished();
	void Update();
	void Done();
	void Start();

private:
	DriveController *driveController;
	GearController *gearController;
	RobotModel *robot;
	bool reachedSetpoint, waitForTimeout;

	double distance, maxSpeed, timeout;

	double P, I, D;
	int target_pass;
	double leftEncoderStartDistance, rightEncoderStartDistance;
};

#endif
