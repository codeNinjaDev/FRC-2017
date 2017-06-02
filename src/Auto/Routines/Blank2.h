/*
 * Blank2.h
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ROUTINES_BLANK2_H_
#define SRC_AUTO_ROUTINES_BLANK2_H_
#include "../AutoRoutine.h"
#include "../../Controllers/LightsController.h"

class Blank2 : public AutoRoutine {
 public:
    Blank2(MasterController* controllers);
    void Prestart();
    virtual ~Blank2();
 protected:
    void Routine();
 private:
    MasterController* controllers;
};

#endif /* SRC_AUTO_ROUTINES_Blank2_H_ */
