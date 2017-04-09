/*
 * DriveForwardRoutine.h
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_
#define SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_

#include "../AutoRoutine.h"
#include "../../LightsController.h"
#include "../../GearController.h"

class DriveForwardRoutine: public AutoRoutine {
public:
	DriveForwardRoutine(RobotModel *robot, DriveController* kDrive, Profile* profile, GearController *gearController, LightsController* lights);
	void Prestart();

protected:
	void Routine();

private:
	DriveController* kDrive;
	GearController* gearController;
	RobotModel *robot;
	LightsController* lights;
	Profile* profile;
};

#endif /* SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_ */
