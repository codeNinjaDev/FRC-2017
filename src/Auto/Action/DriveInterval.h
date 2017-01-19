/*
 * DriveInterval.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ACTION_DRIVEINTERVAL_H_
#define SRC_AUTO_ACTION_DRIVEINTERVAL_H_

#include "Timer.h";
#include "Action.h"


class DriveInterval: public Action {
public:



  DriveInterval(DriveController* drive, double seconds, double y, double x);
  bool isFinished();
  void update();
  void done();
  void start();

  virtual ~DriveInterval();
private:

};

#endif /* SRC_AUTO_ACTION_DRIVEINTERVAL_H_ */
