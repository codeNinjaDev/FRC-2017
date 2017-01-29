/*
 * Action.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ACTION_ACTION_H_
#define SRC_AUTO_ACTION_ACTION_H_
#include "DriveController.h"
#include "Hardware.h"
class Action {

public:

  virtual bool isFinished() = 0;
  virtual void update() = 0;
  virtual void done() = 0;
  virtual void start() = 0;
  virtual ~Action();

protected:
  DriveController *kDrive = Hardware::GetDriveController();

};

#endif /* SRC_AUTO_ACTION_ACTION_H_ */
