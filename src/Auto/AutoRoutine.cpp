/*
 * AutoRoutine.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */
#include "Action/DriveIntervalAction.h"
#include "Action/Action.h"
#include <Auto/AutoRoutine.h>

/*void AutoRoutine::WaitTime(double seconds) {
  AutoBase::runAction(new TimeoutAction(seconds));
}*/
void AutoRoutine::DriveInterval(double seconds, double y, double x) {
  Action temp = new DriveIntervalAction(seconds, y, x);
  AutoBase::runAction(temp);
}

