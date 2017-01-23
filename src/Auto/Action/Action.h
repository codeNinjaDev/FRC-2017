/*
 * Action.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ACTION_ACTION_H_
#define SRC_AUTO_ACTION_ACTION_H_
#include "DriveController.h"

class Action {

public:
  virtual bool isFinished();
  virtual void update();
  virtual void done();
  virtual void start();
  virtual ~Action();
};

#endif /* SRC_AUTO_ACTION_ACTION_H_ */
