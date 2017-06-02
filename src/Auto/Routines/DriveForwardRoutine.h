/*
 * DriveForwardRoutine.h
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_
#define SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_

#include "../AutoRoutine.h"
#include "../../Controllers/LightsController.h"
#include "../../Controllers/GearController.h"

class DriveForwardRoutine: public AutoRoutine {
public:
	DriveForwardRoutine(MasterController* controllers);
	void Prestart();

protected:
	void Routine();

private:
    MasterController* controllers;
};

#endif /* SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_ */
