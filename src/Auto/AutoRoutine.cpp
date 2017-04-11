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
void AutoRoutine::DriveInterval(DriveController* kDrive, double seconds, double y, double x) {
	RunAction(new DriveIntervalAction(kDrive, seconds, y, x));
}


void AutoRoutine::DriveDistanceStraight(RobotModel *robot, DriveController* kDrive, GearController *gearController, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout, LightsController *lights, bool ejectGear) {
  RunAction(new DriveSetpointStraightAction(robot, kDrive, gearController, desired_distance, maxSpeed, timeout, waitForTimeout, lights, ejectGear));
}

void AutoRoutine::DriveDistanceRotate(RobotModel* robot, DriveController* kDrive, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout, LightsController* lights) {
  RunAction(new DriveSetPointRotateAction(robot, kDrive, desired_distance, maxSpeed, timeout, waitForTimeout, lights));
}
void AutoRoutine::WaitTime(double timeout) {
    RunAction(new WaitTimeAction(timeout));
}
void AutoRoutine::VisionSetpointX(VisionController *vision, DriveController *drive, RobotModel *robot, double setpoint, double maxSpeed, double timeout, bool waitForTimeout, LightsController* lights){
	RunAction(new VisionSetpointXAction(vision, drive, robot, setpoint, maxSpeed, timeout, waitForTimeout, lights));
}

void AutoRoutine::GearLifterUp(RobotModel *robot, DriveController* kDrive, GearController *gearController, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout){
  RunAction(new GearLifterUpAction(robot, kDrive, gearController, desired_distance, maxSpeed, timeout, waitForTimeout));
}
void AutoRoutine::GearLifterDown(RobotModel *robot, DriveController* kDrive, GearController *gearController, double desired_distance, double maxSpeed, double timeout, bool waitForTimeout){
  RunAction(new GearLifterDownAction(robot, kDrive, gearController, desired_distance, maxSpeed, timeout, waitForTimeout));
}
void AutoRoutine::ArcadeDriveStraight(RobotModel *robot, DriveController *driveController,
            GearController *gearController, double distance, double maxSpeed, double timeout, bool waitForTimeout,
            LightsController* lights, bool ejectGear) {
    RunAction(new ArcadeDriveStraightAction(robot, driveController, gearController, distance, maxSpeed, timeout, waitForTimeout, lights, ejectGear));

}
