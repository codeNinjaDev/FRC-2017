/*
 * ShootAction.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: peter
 */

#include "ShootAction.h"

ShootAction::ShootAction(double sec, double spd) {
  goal_time = sec;
  speed = spd;
  start_time = 0;
}

bool ShootAction::IsFinished() {
  return (Timer::GetFPGATimestamp() >= start_time + goal_time);
}

void ShootAction::Update() {
  kShooter->SetShooterMotorsSpeed(speed);
}

void ShootAction::Done() {
  kShooter->SetShooterMotorsSpeed(0.0);
}

void ShootAction::Start() {
  start_time = Timer::GetFPGATimestamp();
}
ShootAction::~ShootAction() {
  // TODO Auto-generated destructor stub
}

