#include "WPILib.h"
#include "DriveController.h"
#include "RobotModel.h"
#include "MainController.h"

DriveController::DriveController() {
  kDriveTrain = new RobotDrive(robot->leftDriveMotorA, robot->leftDriveMotorB,
      robot->rightDriveMotorA, robot->rightDriveMotorB);

  m_stateVal = kInitialize;
  nextState = kInitialize;
}

DriveController::~DriveController() {
}

void DriveController::Update(double currTimeSec, double deltaTimeSec) {
  switch (m_stateVal) {
  case (kInitialize):
    nextState = kTeleopDrive;
    break;
  case (kTeleopDrive):
    printf("In case kTeleopDrive \n");

    double driverLeftX;
    driverLeftX = humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
        RemoteControl::kLX);
    double driverLeftY;
    driverLeftY = humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
        RemoteControl::kLY);
    double driverRightX;
    driverRightX = humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
        RemoteControl::kRX);
    double driverRightY;
    driverRightY = humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
        RemoteControl::kRY);

    if (humanControl->GetArcadeDriveDesired()) {
      ArcadeDrive(driverLeftX, driverRightY, true);
    } else {
      TankDrive(driverLeftY, driverRightY);
    }

    nextState = kTeleopDrive;
    break;
  } // end of switch

  m_stateVal = nextState;
}

void DriveController::ArcadeDrive(double myX, double myY, bool teleOp) {

  if (teleOp) {
    if (humanControl->GetReverseDriveDesired()) {
      myX = -myX;
      myY = -myY;
    }

    kDriveTrain->ArcadeDrive(myX, myY, SQUARE_DRIVE_AXIS_INPUT);

  } else {
    kDriveTrain->ArcadeDrive(myX, myY, false);
  }
}

void DriveController::TankDrive(double myLeft, double myRight) {
  if (humanControl->GetReverseDriveDesired()) {
    myLeft = -myLeft;
    myRight = -myRight;
  }

  kDriveTrain->TankDrive(myLeft, myRight, SQUARE_DRIVE_AXIS_INPUT);
}

void DriveController::Reset() {
  m_stateVal = kInitialize;
}

void DriveController::Stop() {
  kDriveTrain->ArcadeDrive(0.00, 0.00, false);
}
