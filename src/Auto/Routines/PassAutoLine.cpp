/*
 * PassAutoLine.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "PassAutoLine.h"
#include "../../Params.h"

PassAutoLine::PassAutoLine(MasterController* controllers) {
    this->controllers = controllers;

}

void PassAutoLine::Routine() {
    controllers->GetGearController()->gearTilterPID->Enable();
    DriveDistanceStraight(controllers, 100.0, 0.4, 4.0, false, false);
    controllers->GetGearController()->gearTilterPID->Disable();
}

void PassAutoLine::Prestart() {
    controllers->GetGearController()->gearTilterPID->SetPID(gear_p, gear_i,
                                                            gear_d);
    controllers->GetGearController()->gearTilterPID->SetOutputRange(-1.0, 1.0);
    controllers->GetGearController()->gearTilterPID->SetSetpoint(
            GEAR_POT_UP_POSITION);
}

// alliance wall 93.45 in

//90 degrees from hopper 173v 100h in
