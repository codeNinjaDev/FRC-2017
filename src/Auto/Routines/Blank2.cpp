/*
 * Blank2.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#include "Blank2.h"

Blank2::Blank2(MasterController* controller) {
    this->robot = controller->GetRobotModel();
    this->driveTrain = controller->GetDriveController();
    this->lights = controller->GetLightsController();
    this->gearController = controller->GetGearController();
}

void Blank2::Prestart() {

}
void Blank2::Routine() {

}


Blank2::~Blank2() {
    // TODO Auto-generated destructor stub
}

