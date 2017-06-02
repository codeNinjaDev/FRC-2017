/*
 * AutoRoutine.cpp
 *Base class for all autonomous routines to implement functions
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#include <Auto/AutoRoutineRunner.h>
#include "AutoRoutine.h"
#include "WPILib.h"
#include <DriverStation.h>

void AutoRoutine::Run() {
	m_active = true;
	Routine();

}

void AutoRoutine::Stop() {
	m_active = false;
}

bool AutoRoutine::IsActive() {
	return m_active;
}

void AutoRoutine::RunAction(Action* action) {
	action->Start();
	while ((IsActive()) && (!action->IsFinished()) && (AutoRoutineRunner::GetTimer()->Get() <= 15) && RobotState::IsAutonomous() && !RobotState::IsDisabled()) {
		action->Update();
	}
	action->Done();
}

//ACTIONS:
void AutoRoutine::DriveInterval(MasterController* kDrive, double seconds, double y, double x) {
	RunAction(new DriveIntervalAction(kDrive, seconds, y, x));
}


void AutoRoutine::DriveDistanceStraight(MasterController* controllers, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout, bool ejectGear) {
  RunAction(new DriveSetPointStraightAction(controllers, desired_distance, maxSpeed, timeout, waitForTimeout, ejectGear));
}

void AutoRoutine::DriveDistanceRotate(MasterController* controllers, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout) {
  RunAction(new DriveSetPointRotateAction(controllers, desired_distance, maxSpeed, timeout, waitForTimeout));
}
void AutoRoutine::WaitTime(double timeout) {
    RunAction(new WaitTimeAction(timeout));
}
void AutoRoutine::VisionSetpointX(MasterController* controllers, double setpoint, double maxSpeed, double timeout, bool waitForTimeout){
	RunAction(new VisionSetpointXAction(controllers, setpoint, maxSpeed, timeout, waitForTimeout));
}

void AutoRoutine::GearLifterUp(MasterController* controllers, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout){
  RunAction(new GearLifterUpAction(controllers, desired_distance, maxSpeed, timeout, waitForTimeout));
}
void AutoRoutine::GearLifterDown(MasterController* controllers, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout){
  RunAction(new GearLifterDownAction(controllers, desired_distance, maxSpeed, timeout, waitForTimeout));
}
