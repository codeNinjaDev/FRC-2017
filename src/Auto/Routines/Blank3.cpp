/*
 * Blank3.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#include "Blank3.h"

Blank3::Blank3(MasterController* controller) {
    this->robot = controller->GetRobotModel();
    this->driveTrain = controller->GetDriveController();
    this->lights = controller->GetLightsController();
    this->gearController = controller->GetGearController();
}

void Blank3::Prestart() {

}
void Blank3::Routine() {

}


Blank3::~Blank3() {
    // TODO Auto-generated destructor stub
}

