/*
 * CenterGear.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "CenterGear.h"
CenterGear::CenterGear(VisionController* vision, RobotModel* robot,
                       DriveController* driveTrain, GearController* gearController, LightsController* lights) {
    this->vision = vision;
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->lights = lights;
    this->gearController = gearController;
}
void CenterGear::Routine() {
	gearController->GearPIDUp();
	NewStraight(robot, driveTrain, gearController, lights, 75.0, 0.3, 4.0, 0.4);
	gearController->GearDown();
	DriveDistanceStraight(robot, driveTrain, gearController, -5.0, 0.25, 1.5, true, lights, true);
}

void CenterGear::Prestart() {
}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

