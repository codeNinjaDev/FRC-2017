/*
 * DriveInterval.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ACTION_DRIVEINTERVALACTION_H_
#define SRC_AUTO_ACTION_DRIVEINTERVALACTION_H_

#include <Timer.h>
#include "Action.h"
#include "MainController.h"


class DriveIntervalAction: public Action {
public:


  DriveIntervalAction(double seconds, double y, double x);
  bool isFinished();
  void update();
  void done();
  void start();

  virtual ~DriveIntervalAction();
};

#endif /* SRC_AUTO_ACTION_DRIVEINTERVALACTION_H_ */
