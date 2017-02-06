#include "WPILib.h"
#include "RobotModel.h"
#include "DriveController.h"
#include "SuperstructureController.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
#include "DashboardLogger.h"
#include "ShooterController.h"
#include <string.h>
#include "Hardware.h"

class MainProgram: public frc::IterativeRobot {
  //LiveWindow helps in Test mode
  //LiveWindow *lw;
  //Creates a robot from class RobotModel
  RobotModel *robot;
  //Creates a human control from RemoteControl, which includes ControlBoard
  RemoteControl *humanControl;
  //Creates a controller for drivetrain and superstructure
  DriveController *driveController;
  SuperstructureController *superstructureController;
  ShooterController *shooterController;
  //Creates an object of Dashboardlogger
  DashboardLogger *dashboardLogger;
  Hardware hardware;

  //Creates a time-keeper
  double currTimeSec;
  double lastTimeSec;
  double deltaTimeSec;
public:
  MainProgram(void) {
    robot = hardware.GetRobot();
    humanControl = hardware.GetHumanControl();
    driveController = hardware.GetDriveController();
    dashboardLogger = hardware.GetDashboardLogger();
    shooterController = hardware.GetShooterController();
    superstructureController = hardware.GetSuperstructureController();
    //Initializes timekeeper variables
    currTimeSec = 0.0;
    lastTimeSec = 0.0;
    deltaTimeSec = 0.0;
  }
private:
  void RobotInit() {
    robot->ResetTimer();
    robot->Reset();

  }

  void AutonomousInit() {
    robot->ResetTimer();

    driveController->Reset();

    superstructureController->Reset();

    //Resets timer variables
    currTimeSec = 0.0;
    lastTimeSec = 0.0;
    deltaTimeSec = 0.0;

  }

  void AutonomousPeriodic() {
    dashboardLogger->UpdateData();

    //Timer is updated
    lastTimeSec = currTimeSec;
    currTimeSec = robot->GetTime();
    deltaTimeSec = currTimeSec - lastTimeSec;

    //robot->UpdateCurrent();
  }

  void TeleopInit() {

    robot->ResetTimer();

    driveController->Reset();

    superstructureController->Reset();
    shooterController->Reset();

    //Resets timer variables
    currTimeSec = 0.0;
    lastTimeSec = 0.0;
    deltaTimeSec = 0.0;

  }

  void TeleopPeriodic() {
    dashboardLogger->UpdateData();

    //Updates timer
    lastTimeSec = currTimeSec;
    currTimeSec = robot->GetTime();
    deltaTimeSec = currTimeSec - lastTimeSec;

    //robot->UpdateCurrent();

    //Reads controls and updates controllers accordingly
    humanControl->ReadControls();
    driveController->Update(currTimeSec, deltaTimeSec);
    shooterController->Update(currTimeSec, deltaTimeSec);
    superstructureController->Update(currTimeSec, deltaTimeSec);
  }

  void DisabledInit() {

    driveController->Reset();

    superstructureController->Reset();

  }

  void DisabledPeriodic() {
    dashboardLogger->UpdateData();
    SmartDashboard::PutBoolean("HUMANSHOOTLOOPDESIRED", false);
    //robot->UpdateCurrent();

    //Reads controls and updates controllers accordingly
    humanControl->ReadControls();
  }
};

START_ROBOT_CLASS(MainProgram);
