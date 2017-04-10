#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
#include "DashboardLogger.h"
#include "LightsController.h"
#include "ClimberController.h"
#include "DriveController.h"
#include "VisionController.h"
#include "GearController.h"
#include "MotionController.h"
#include <string.h>
#include "Auto/Auto.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <pathfinder.h>

class MainProgram : public frc::IterativeRobot {

    RobotModel *robot;
    RemoteControl *humanControl;
    Auto *auton;

    VisionController *visionController;
    DriveController *driveController;
    DashboardLogger *dashboardLogger;
    ClimberController *climberController;
    LightsController* lights;
    GearController *gearController;
    MotionController *motionController;

    //Creates a time-keeper	`
    double currTimeSec;
    double lastTimeSec;
    double deltaTimeSec;

 public:
    MainProgram(void) {
        robot = new RobotModel();
        humanControl = new ControlBoard();
        lights = new LightsController(humanControl);
        visionController = new VisionController();
        driveController = new DriveController(robot, humanControl, visionController);
        dashboardLogger = new DashboardLogger(robot, humanControl);
        climberController = new ClimberController(robot, humanControl);
        gearController = new GearController(robot, humanControl);
        auton = new Auto(visionController, driveController, robot, gearController, lights);

        //Initializes timekeeper variables
        currTimeSec = 0.0;
        lastTimeSec = 0.0;
        deltaTimeSec = 0.0;
    }
 private:
    void RobotInit() {
        RefreshAllIni();
        robot->ResetTimer();
        robot->Reset();
        auton->ListOptions();
        visionController->Disable();

        //Start camera thread
        std::thread cameraThread(CameraThread);
        cameraThread.detach();

    }

    void AutonomousInit() {
        auton->Stop();
        RefreshAllIni();
        robot->ResetTimer();
        robot->ResetEncoders();

        driveController->Reset();

        //Resets timer variables
        currTimeSec = 0.0;
        lastTimeSec = 0.0;
        deltaTimeSec = 0.0;

        visionController->Enable();
        auton->Start();
    }

    void AutonomousPeriodic() {
        //Autonoumous is running in a thread called by "auton->Start();"
        dashboardLogger->UpdateData();  //Joystick data does NOT update during autonomous
        visionController->Update();
    }

    void TeleopInit() {
        motionController = new MotionController();
        lights->SetEnabledRoutine();
        auton->Stop();
        RefreshAllIni();
        robot->ResetTimer();
        robot->ResetEncoders();

        driveController->Reset();
        climberController->Reset();
        gearController->Reset();

        //Resets timer variables
        currTimeSec = 0.0;
        lastTimeSec = 0.0;
        deltaTimeSec = 0.0;

        visionController->Enable();

    }

    void TeleopPeriodic() {
        dashboardLogger->UpdateEssentialData();

        //Updates timer
        lastTimeSec = currTimeSec;
        currTimeSec = robot->GetTime();
        deltaTimeSec = currTimeSec - lastTimeSec;


        //Reads controls and updates controllers accordingly
        //RefreshAllIni();
        humanControl->ReadControls();
        driveController->Update(currTimeSec, deltaTimeSec);
        climberController->Update();
        visionController->Update();
        gearController->Update();

        if (humanControl->GetJoystickValue(RemoteControl::kOperatorJoy, RemoteControl::kRY) > 0.2) {
        lights->Climbing();
        } else if (humanControl->GetShoutRoutineDesired()) {
        lights->SetShoutRoutine();
        } else if (humanControl->GetGearTitlerIntakeDesired()) {
        lights->GearIntake();

        } else if (humanControl->GetGearTitlerOuttakeDesired()) {
        lights->GearOuttake();

        } else if (humanControl->GetSlowDriveTier1Desired()
                && humanControl->GetSlowDriveTier2Desired()) {
        lights->Brake2();

        } else if (humanControl->GetSlowDriveTier1Desired()) {
        lights->Brake1();

        } else {
        lights->SetEnabledRoutine();
        }
    }

    void DisabledInit() {
        auton->Stop();

        RefreshAllIni();

        robot->ResetEncoders();
        driveController->Reset();
        climberController->Reset();
        visionController->Disable();
        lights->SetDisabledRoutine();
    }

    void DisabledPeriodic() {
        auton->ChangedRoutines();
        dashboardLogger->UpdateData();

        visionController->Update();
        humanControl->ReadControls();
        gearController->Update();
        RefreshAllIni();
    }
    void RefreshAllIni() {
        robot->RefreshIni();
    }

    static void CameraThread() {
		cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
		camera.SetResolution(352, 288);
		cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo();
		cs::CvSource outputStreamStd = CameraServer::GetInstance()->PutVideo("Gray", 640, 480);
		cv::Mat source;
		cv::Mat output;
		while(true) {
			cvSink.GrabFrame(source);
			cvtColor(source, output, cv::COLOR_BGR2GRAY);
			outputStreamStd.PutFrame(output);
		}
    }
};

START_ROBOT_CLASS(MainProgram);
