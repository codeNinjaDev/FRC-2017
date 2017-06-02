/*
 * Blank1.h
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ROUTINES_BLANK1_H_
#define SRC_AUTO_ROUTINES_BLANK1_H_
#include "../AutoRoutine.h"
#include "../../Controllers/LightsController.h"
class Blank1 : public AutoRoutine {
 public:
    Blank1(MasterController* controller);
    void Prestart();
    virtual ~Blank1();
 protected:
    void Routine();
 private:
    MasterController* controllers;
};

#endif /* SRC_AUTO_ROUTINES_BLANK1_H_ */
