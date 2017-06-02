/*
 * CenterGear.h
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ROUTINES_CENTERGEAR_H_
#define SRC_AUTO_ROUTINES_CENTERGEAR_H_

#include "../AutoRoutine.h"
#include "../../Controllers/LightsController.h"

class CenterGear : public AutoRoutine {
 public:
    CenterGear(MasterController* controllers);

  virtual ~CenterGear();
  void Prestart();

 private:
  MasterController* controllers;
 protected:
  void Routine();
};


#endif /* SRC_AUTO_ROUTINES_CENTERGEAR_H_ */
