/*
 * AutoRoutine.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#include <Auto/AutoRoutine.h>
#include "AutoBase.h"
/*void AutoRoutine::WaitTime(double seconds) {
  AutoBase::runAction(new TimeoutAction(seconds));
}*/

void AutoRoutine::DriveInterval(double seconds, double y, double x) {

  AutoBase::runAction(new DriveIntervalAction(seconds, y, x));

}

