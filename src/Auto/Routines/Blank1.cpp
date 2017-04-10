/*
 * Blank1.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#include "Blank1.h"

Blank1::Blank1(MasterController* controller) {
    this->robot = controller->GetRobotModel();
    this->driveTrain = controller->GetDriveController();
    this->lights = controller->GetLightsController();
    this->gearController = controller->GetGearController();
}

void Blank1::Prestart() {

}
void Blank1::Routine() {

}


Blank1::~Blank1() {
    // TODO Auto-generated destructor stub
}

