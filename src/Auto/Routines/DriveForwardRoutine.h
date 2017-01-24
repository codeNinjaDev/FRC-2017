/*
 * DriveForwardRoutine.h
 *
 *  Created on: Jan 23, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_
#define SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_

#include "../AutoRoutine.h"

class DriveForwardRoutine : public AutoRoutine {
public:
  void prestart();
  virtual ~DriveForwardRoutine();

protected:
  void routine();
};

#endif /* SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_ */
