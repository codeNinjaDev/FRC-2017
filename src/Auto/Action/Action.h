/*
 * Action.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ACTION_ACTION_H_
#define SRC_AUTO_ACTION_ACTION_H_
#include "../../Hardware.h"

class Action {

public:

  virtual bool IsFinished();
  virtual void Update();
  virtual void Done();
  virtual void Start();
  virtual ~Action();

protected:
  DriveController *kDrive = Hardware::GetDriveController();

};

#endif /* SRC_AUTO_ACTION_ACTION_H_ */
