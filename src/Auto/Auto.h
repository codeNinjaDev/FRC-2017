/*
 * Auto.h
 *
 *  Created on: Jan 28, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTO_H_
#define SRC_AUTO_AUTO_H_
#include <Auto/AutoRoutineRunner.h>
#include <Auto/AutoSelector.h>
#include "AutoRoutine.h"
#include "../DriveController.h"
#include "../RobotModel.h"
#include "../VisionController.h"
#include "../GearController.h"
#include "MasterController.h"
#include "../LightsController.h"
class Auto {
public:
	Auto(MasterController* controller);

	bool ReturnBool();
	AutoRoutine* autoRoutine;
	void Reset();
	void ListOptions();
	void Start();
	void Stop();
	AutoSelector* selector;
	AutoRoutineRunner* autoRoutineRunner;
	virtual ~Auto();
private:

};

#endif /* SRC_AUTO_AUTO_H_ */
