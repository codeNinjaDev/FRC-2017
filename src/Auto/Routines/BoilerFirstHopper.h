/*
 * BoilerFirstHopper.h
 *
 *  Created on: Mar 18, 2017
 *      Author: mikec
 */

#ifndef SRC_AUTO_ROUTINES_BOILERFIRSTHOPPER_H_
#define SRC_AUTO_ROUTINES_BOILERFIRSTHOPPER_H_

#include "../AutoRoutine.h"
#include "Controllers/LightsController.h"
class BoilerFirstHopper : public AutoRoutine {
public:
 BoilerFirstHopper(MasterController* controllers);
 void Prestart();

private:
 MasterController* controllers;
protected:
 void Routine();
};

#endif /* SRC_AUTO_ROUTINES_BOILERFIRSTHOPPER_H_ */
