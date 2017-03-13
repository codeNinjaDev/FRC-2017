/*
 * ShootPIDAction.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: peter
 */

#include "ShootPIDAction.h"
#include "Timer.h"

ShootPIDAction::ShootPIDAction(RobotModel* robot, ShooterController* shooter, double timeout) {
    goal_time = timeout;
    this->robot = robot;
    this->timeout = timeout;
    this->shooter = shooter;
    reachedRPM = false;
    P = 0.8;
    I = 0.0;
    D = 0.0;
}
bool ShootPIDAction::IsFinished() {
    return (Timer::GetFPGATimestamp() >= start_time + goal_time) || (reachedRPM);

}

void ShootPIDAction::Update() {
    robot->SetFeederMotorSpeed(FEEDER_HARDSET_MOTOR_SPEED);
    if (shooter->shooterPID->OnTarget()
            && (Timer::GetFPGATimestamp() >= start_time + timeout)) {
    reachedRPM = true;
    } else {
    reachedRPM = false;
    }
    SmartDashboard::PutBoolean("ACTION_SHOOTER_PID", true);
}

void ShootPIDAction::Done() {
    robot->SetFeederMotorSpeed(0.0);
    shooter->shooterPID->Disable();
    robot->SetShooterMotorsSpeed(0.0);
}

void ShootPIDAction::Start() {
    robot->SetFeederMotorSpeed(FEEDER_HARDSET_MOTOR_SPEED);
    start_time = Timer::GetFPGATimestamp();
    shooter->shooterPID->Reset();
    shooter->shooterPID->Enable();
}
ShootPIDAction::~ShootPIDAction() {
    // TODO Auto-generated destructor stub
}

