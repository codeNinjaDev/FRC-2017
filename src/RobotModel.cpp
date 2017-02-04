/*
 * RobotModel.cpp
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#include "WPILib.h"
#include "RobotModel.h"
#include "Ports.h"

//RobotModel constructor: inits all variables and objects
RobotModel::RobotModel() {
  pdp = new PowerDistributionPanel();

  leftDriveMotorA = new Talon(LEFT_DRIVE_MOTOR_A_PWM_PORT);
  leftDriveMotorB = new Talon(LEFT_DRIVE_MOTOR_B_PWM_PORT);
  rightDriveMotorA = new Talon(RIGHT_DRIVE_MOTOR_A_PWM_PORT);
  rightDriveMotorB = new Talon(RIGHT_DRIVE_MOTOR_B_PWM_PORT);

  //Init shooter motor
  shooterMotorA = new Spark(SHOOTER_MOTOR_A_PWM_PORT);
  shooterMotorB = new Spark(SHOOTER_MOTOR_B_PWM_PORT);

  shooterEncoder = new Encoder(SHOOTER_ENCODER_PORTS[0], SHOOTER_ENCODER_PORTS[1]);
  
  shooterEncoder->SetPIDSourceType(PIDSourceType::kRate);
  shooterEncoder->SetDistancePerPulse((double)1/2048);

  shooterEncoder->SetPIDSourceType(PIDSourceType::kRate);
  leftDriveMotorA->SetSafetyEnabled(false);
  leftDriveMotorB->SetSafetyEnabled(false);
  rightDriveMotorA->SetSafetyEnabled(false);
  rightDriveMotorB->SetSafetyEnabled(false);
  shooterMotorA->SetSafetyEnabled(false);
  shooterMotorB->SetSafetyEnabled(false);

  leftDriveMotorA->SetInverted(false);
  leftDriveMotorB->SetInverted(false);
  rightDriveMotorA->SetInverted(false);
  rightDriveMotorB->SetInverted(false);
  shooterMotorA->SetInverted(false);
  shooterMotorB->SetInverted(false);

  leftDriveACurrent = 0;
  leftDriveBCurrent = 0;
  rightDriveACurrent = 0;
  rightDriveBCurrent = 0;
  shooterMotorACurrent = 0;
  shooterMotorBCurrent = 0;

  timer = new Timer();
  timer->Start();

}

RobotModel::~RobotModel() {
  // TODO Auto-generated destructor stub
}

//resets variables and objects
void RobotModel::Reset() {

}

//returns the voltage
double RobotModel::GetVoltage() {
  return pdp->GetVoltage();
}

//returns the total energy of the PDP
double RobotModel::GetTotalCurrent() {
  return pdp->GetTotalCurrent();
}
//returns the total current of the PDP
double RobotModel::GetTotalEnergy() {
  return pdp->GetTotalEnergy();
}

//returns the total power of the PDP
double RobotModel::GetTotalPower() {
  return pdp->GetTotalPower();
}

//initializes variables pertaining to current
void RobotModel::UpdateCurrent() {
  leftDriveACurrent = pdp->GetCurrent(LEFT_DRIVE_MOTOR_A_PDP_CHAN);
  leftDriveBCurrent = pdp->GetCurrent(LEFT_DRIVE_MOTOR_B_PDP_CHAN);
  rightDriveACurrent = pdp->GetCurrent(RIGHT_DRIVE_MOTOR_A_PDP_CHAN);
  rightDriveBCurrent = pdp->GetCurrent(RIGHT_DRIVE_MOTOR_B_PDP_CHAN);
  shooterMotorACurrent = pdp->GetCurrent(SHOOTER_MOTOR_A_PDP_CHAN);
  shooterMotorBCurrent = pdp->GetCurrent(SHOOTER_MOTOR_B_PDP_CHAN);
}

//returns the current of a given channel
double RobotModel::GetCurrent(int channel) {
  switch (channel) {
  case RIGHT_DRIVE_MOTOR_A_PDP_CHAN:
    return rightDriveACurrent;
    break;
  case RIGHT_DRIVE_MOTOR_B_PDP_CHAN:
    return rightDriveBCurrent;
    break;
  case LEFT_DRIVE_MOTOR_A_PDP_CHAN:
    return leftDriveACurrent;
    break;
  case LEFT_DRIVE_MOTOR_B_PDP_CHAN:
    return leftDriveBCurrent;
    break;
  case SHOOTER_MOTOR_A_PDP_CHAN:
    return shooterMotorACurrent;
    break;
  case SHOOTER_MOTOR_B_PDP_CHAN:
    return shooterMotorBCurrent;
  default:
    return -1;
  }
}

//resets the time
void RobotModel::ResetTimer() {
  timer->Reset();
}

//returns the time
double RobotModel::GetTime() {
  return timer->Get();
}

// SUPERSTRUCTURE ACCESSORS AND MUTATORS IN ROBOTMODEL

double RobotModel::GetShooterMotorASpeed() {
  return shooterMotorA->Get();
}

double RobotModel::GetShooterMotorBSpeed() {
  return shooterMotorB->Get();
}

void RobotModel::SetShooterMotorsSpeed(double speed){
  shooterMotorA->Set(speed);
  shooterMotorB->Set(speed);
}
