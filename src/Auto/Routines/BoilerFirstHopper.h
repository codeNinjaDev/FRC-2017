/*
 * BoilerFirstHopper.h
 *
 *  Created on: Mar 18, 2017
 *      Author: mikec
 */

#ifndef SRC_AUTO_ROUTINES_BOILERFIRSTHOPPER_H_
#define SRC_AUTO_ROUTINES_BOILERFIRSTHOPPER_H_

#include "../AutoRoutine.h"
#include "LightsController.h"
class BoilerFirstHopper : public AutoRoutine {
public:
 BoilerFirstHopper(RobotModel *robot, DriveController* driveTrain, Profile* profile,GearController *gearController, LightsController* lights);
 void Prestart();

private:
 DriveController *driveTrain;
 RobotModel *robot;
 LightsController* lights;
 GearController *gearController;
 Profile* profile;
protected:
 void Routine();
};

#endif /* SRC_AUTO_ROUTINES_BOILERFIRSTHOPPER_H_ */
