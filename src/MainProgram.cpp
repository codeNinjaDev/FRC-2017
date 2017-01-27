#include "WPILib.h"
#include "RobotModel.h"
#include "DriveController.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
#include "DashboardLogger.h"
#include <string.h>
#include "Hardware.h"
class MainProgram: public frc::IterativeRobot {



  RobotModel* robot;
  RemoteControl* humanControl;
  DriveController* driveController;
  DashboardLogger* dashboardLogger;
  LiveWindow* lw;

  //Creates a time-keeper
  double currTimeSec;
  double lastTimeSec;
  double deltaTimeSec;
public:
  MainProgram(void) {
    robot = Hardware::GetRobot();
    humanControl = Hardware::GetHumanControl();
    driveController = Hardware::GetDriveController();
    dashboardLogger = Hardware::GetDashboardLogger();
    lw = Hardware::GetLiveWindow();

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

    robot->UpdateCurrent();
  }

  void TeleopInit() {

    robot->ResetTimer();

    driveController->Reset();

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

    robot->UpdateCurrent();

    //Reads controls and updates controllers accordingly
    humanControl->ReadControls();
    driveController->Update(currTimeSec, deltaTimeSec);
  }

  void DisabledInit() {

    driveController->Reset();

  }

  void DisabledPeriodic() {
    dashboardLogger->UpdateData();

    robot->UpdateCurrent();

    //Reads controls and updates controllers accordingly
    humanControl->ReadControls();
  }
};

START_ROBOT_CLASS(MainProgram);
