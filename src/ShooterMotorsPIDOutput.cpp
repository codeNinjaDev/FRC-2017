#include "ShooterMotorsPIDOutput.h"
#include "WPILib.h"
ShooterMotorsPIDOutput::ShooterMotorsPIDOutput(Victor *kOutputMotor1, Victor *kOutputMotor2) {
  shooterMotorA = kOutputMotor1;
  shooterMotorB = kOutputMotor2;
}

//Override
void ShooterMotorsPIDOutput::PIDWrite(double output) {
  loopOutput = output;

  shooterMotorA->Set(output);
  shooterMotorB->Set(output);
}

double ShooterMotorsPIDOutput::GetPIDLoopOutput() {
  return loopOutput;
}
