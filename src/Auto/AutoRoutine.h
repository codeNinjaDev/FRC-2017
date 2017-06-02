/*
 * AutoRoutine.h
 * Base class for all autonomous actions to implement functions
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTOROUTINE_H_
#define SRC_AUTO_AUTOROUTINE_H_
#include "../Controllers/LightsController.h"
#include "../Controllers/GearController.h"

#include <Auto/Action/DriveSetPointStraightAction.h>
#include "WPILib.h"
#include <iostream>
#include "Action/Action.h"
#include "Action/DriveIntervalAction.h"
#include "Action/DriveSetPointRotateAction.h"
#include "Action/WaitTimeAction.h"
#include "Action/VisionSetpointXAction.h"
#include "Action/GearLifterUpAction.h"
#include "Action/GearLifterDownAction.h"
#include "MasterController.h"
class AutoRoutine {
public:

  bool m_active = false;
  bool *teleop;
  virtual void Prestart() = 0;
  bool IsActive();
  void Run();
  void Stop();
  void RunAction(Action* action);

  //ACTIONS:
  void DriveInterval(MasterController* kDrive, double seconds, double y, double x);
  void DriveDistanceStraight(MasterController* controllers, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout,bool ejectGear);
  void DriveDistanceRotate(MasterController* controllers, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout);
  void VisionSetpointX(MasterController* controllers, double setpoint, double maxSpeed, double timeout, bool waitForTimeout);
  void GearLifterUp(MasterController* controllers, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout);
  void GearLifterDown(MasterController* controllers, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout);

void WaitTime(double distance);
protected:
	virtual void Routine(void) = 0;
private:
	DriverStation* driverStation;
};

#endif /* SRC_AUTO_AUTOROUTINE_H_ */
