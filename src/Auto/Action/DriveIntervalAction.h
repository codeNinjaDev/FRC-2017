/*
 * DriveInterval.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ACTION_DRIVEINTERVALACTION_H_
#define SRC_AUTO_ACTION_DRIVEINTERVALACTION_H_
#include <Timer.h>
#include "MainController.h"
#include "Action.h"


class DriveIntervalAction : public Action {
public:



  DriveIntervalAction(double seconds, double y, double x);
  virtual bool isFinished();
  virtual void update();
  virtual void done();
  virtual void start();

  virtual ~DriveIntervalAction();
private:

};

#endif /* SRC_AUTO_ACTION_DRIVEINTERVALACTION_H_ */
