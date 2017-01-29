/*
 * AutoRoutine.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTOROUTINE_H_
#define SRC_AUTO_AUTOROUTINE_H_

#include "AutoBase.h"
#include "Action/Action.h"
#include "Action/DriveIntervalAction.h"

class AutoRoutine : public AutoBase {
public:
  void DriveInterval(double seconds, double y, double x);
  virtual ~AutoRoutine();
};

#endif /* SRC_AUTO_AUTOROUTINE_H_ */
