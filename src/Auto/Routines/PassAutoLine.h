/*
 * PassAutoLine.h
 *
 *  Created on: Mar 11, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_PASSAUTOLINE_H_
#define SRC_AUTO_ROUTINES_PASSAUTOLINE_H_
#include "../../Controllers/LightsController.h"
#include "../AutoRoutine.h"
class PassAutoLine : public AutoRoutine {
 public:
    PassAutoLine(MasterController* controllers);
    void Prestart();

   private:
    MasterController* controllers;
   protected:
    void Routine();
};



#endif /* SRC_AUTO_ROUTINES_PASSAUTOLINE_H_ */
