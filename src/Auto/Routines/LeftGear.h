/*
 * LeftGear.h
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_LEFTGEAR_H_
#define SRC_AUTO_ROUTINES_LEFTGEAR_H_
#include "../AutoRoutine.h"
#include "../../Controllers/LightsController.h"

class LeftGear : public AutoRoutine {
 public:
    LeftGear(MasterController* controllers);

    void Prestart();

 private:
    MasterController* controllers;
 protected:
    void Routine();
};

#endif /* SRC_AUTO_ROUTINES_LEFTGEAR_H_ */
