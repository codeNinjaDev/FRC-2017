/*
 * RightGear.h
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_RIGHTGEAR_H_
#define SRC_AUTO_ROUTINES_RIGHTGEAR_H_
#include "../AutoRoutine.h"
#include "../../Controllers/LightsController.h"

class RightGear : public AutoRoutine {
 public:

    RightGear(MasterController* controllers);
    void Prestart();

 private:
    MasterController* controllers;
 protected:
    void Routine();
};

#endif /* SRC_AUTO_ROUTINES_RightGEAR_H_ */
