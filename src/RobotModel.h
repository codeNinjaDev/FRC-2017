/*
 * RobotModel.h
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#ifndef SRC_ROBOTMODEL_H_
#define SRC_ROBOTMODEL_H_

#include "WPILib.h"
#include "Ports.h"

class RobotModel {
public:
  RobotModel();
  virtual ~RobotModel();

  void Reset(); //resets variables and objects

  void UpdateCurrent(); //initializes variables pertaining to current

  double GetVoltage(); //returns the voltage
  double GetTotalEnergy(); //returns the total energy of the PDP
  double GetTotalCurrent(); //returns the total current of the PDP
  double GetTotalPower(); //returns the total power of the PDP
  double GetCurrent(int channel); //returns the current of a given channel

  void ResetTimer(); //resets the timer
  double GetTime(); //returns the time

  //Superstructure systems
	double GetShooterMotorSpeed(); //returns the speed of the shooter motor
	void SetShooterMotorSpeed(double speed);//sets the speed of the shooter motor
	
	Talon *leftDriveMotorA, *leftDriveMotorB, *rightDriveMotorA,
      *rightDriveMotorB;
  
  Talon *shooterMotor;

private:
  PowerDistributionPanel* pdp;

  Timer *timer;

  double leftDriveACurrent, leftDriveBCurrent, rightDriveACurrent,
      rightDriveBCurrent, shooterMotorCurrent;
};

#endif /* SRC_ROBOTMODEL_H_ */
