/*
 * ShootHighGoal.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "ShootHighGoal.h"

ShootHighGoal::ShootHighGoal(RobotModel *robot, DriveController* driveTrain, ShooterController* shooter) {
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->shooter = shooter;
}

void ShootHighGoal::Prestart() {

}

void ShootHighGoal::Routine() {
    //drive backwards five feet
    DriveDistanceStraight(robot, driveTrain, (-5*12.0), .8, 4.0, 4.0, false);
    //turn 45 degrees clockwise
    DriveDistanceStraight(robot, driveTrain, 45.0, .8, 4.0, 4.0, false);
    //drive forward four fee
    DriveDistanceStraight(robot, driveTrain, (4*12.0), .8, 4.0, 4.0, false);
    //Shoot
    ShootPID(robot, shooter, 15.0);


}
