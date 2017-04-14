/*
 * DriveSetPoint.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "ArcadeDriveStraightAction.h"
#include "WPILib.h"
//distance: distance in inches for the bot to rotate
//maxSpeed: max speed robot can drive to hit setpoint
//timeout: amount of allowed time this action can run before ending
ArcadeDriveStraightAction::ArcadeDriveStraightAction(
        RobotModel *robot, DriveController *driveController,
        GearController *gearController, double distance, double maxSpeed,
        double timeout, bool waitForTimeout, LightsController* lights,
        bool ejectGear) {
    this->driveController = driveController;
    this->distance = distance;
    this->timeout = timeout;
    this->robot = robot;
    this->maxSpeed = maxSpeed;
    this->waitForTimeout = waitForTimeout;
    this->lights = lights;
    this->gearController = gearController;
    this->ejectGear = ejectGear;
    reachedSetpoint = false;
    leftEncoderStartDistance, rightEncoderStartDistance = 0.0;

    P = 0.3;
    I = robot->pini->getf("DRIVE_PID", "drive_i", 0.0);
    D = robot->pini->getf("DRIVE_PID", "drive_d", 0.0);
    SmartDashboard::PutNumber("DRIVE_PID_P", P);
    SmartDashboard::PutNumber("DRIVE_PID_I", I);
    SmartDashboard::PutNumber("DRIVE_PID_D", D);
}

bool ArcadeDriveStraightAction::IsFinished() {
    if ((Timer::GetFPGATimestamp() >= start_time + timeout)
            && !(reachedSetpoint)) {
    }
    if (waitForTimeout)
        return (Timer::GetFPGATimestamp() >= start_time + timeout);
    else
        return (Timer::GetFPGATimestamp() >= start_time + timeout)
                || reachedSetpoint;
    if (ejectGear)
        robot->SetGearIntakeSpeed(-GEAR_WHEELS_ACTIVE_MOTOR_SPEED);

}

void ArcadeDriveStraightAction::Update() {
    if (driveController->arcadePID->OnTarget()) {
    reachedSetpoint = true;
    } else {
    reachedSetpoint = false;
    }
}

void ArcadeDriveStraightAction::Done() {
    driveController->arcadePID->Disable();
    driveController->Stop();
}

void ArcadeDriveStraightAction::Start() {
    start_time = Timer::GetFPGATimestamp();

    robot->leftDriveEncoder->Reset();
    robot->rightDriveEncoder->Reset();

    leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
    rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();
    double averageEncoderStartDistance = (leftEncoderStartDistance
            + rightEncoderStartDistance) / 2.0;
    driveController->arcadePID->SetOutputRange(-maxSpeed, maxSpeed);
    driveController->arcadePID->SetPID(P, I, D);
    driveController->arcadePID->SetSetpoint(
            distance + averageEncoderStartDistance);

    driveController->arcadePID->Enable();
}
