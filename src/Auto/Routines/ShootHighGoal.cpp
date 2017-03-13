/*
 * ShootHighGoal.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "ShootHighGoal.h"

ShootHighGoal::ShootHighGoal(RobotModel *robot, DriveController* driveTrain) {
    this->robot = robot;
    this->driveTrain = driveTrain;
}

void ShootHighGoal::Prestart() {

}

void ShootHighGoal::Routine() {
    //drive backwards five feet
    DriveDistanceStraight(robot, driveTrain, (-5*12.0), .8, 5.0, 5.0, false);
    //turn 45 degrees clockwise
    DriveDistanceStraight(robot, driveTrain, 45.0, .8, 5.0, 5.0, false);
    //drive forward four feet
    DriveDistanceStraight(robot, driveTrain, (4*12.0), .8, 5.0, 5.0, false);

}
