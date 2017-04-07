#ifndef DRIVECONTROLLER_H_
#define DRIVECONTROLLER_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"
#include "DriveYMotorsPIDOutput.h"
#include "DriveRotateMotorsPIDOutput.h"
#include "DriveEncodersPIDSource.h"
#include "DashboardLogger.h"
#include "VisionController.h"
#include "VisionPIDSource.h"
#include "ini.h"
#include "WheelsPIDOutput.h"
#include <iostream>

class PivotCommand;

class DriveController {
 public:
    DriveController(RobotModel *myRobot, RemoteControl *myHumanControl,
                    VisionController *myVision);
    virtual ~DriveController();

    void Stop();
    void Update(double currTimeSec, double deltaTimeSec);
    void Reset();
    void ArcadeDrive(double myX, double myY, bool teleOp);
    void TankDrive(double myLeft, double myRight);
    void RefreshIni();
    void TurnAngle(double angle);
    double CheezyCalculate(double input);
    enum DriveState {
        kInitialize,
        kTeleopDrive
    };

    PIDOutput *leftPIDOutput;
    PIDController *leftPID;

    PIDOutput *rightPIDOutput;
    PIDController *rightPID;

    PIDOutput *driveXPIDOutput;
    PIDController *visionPID;
    VisionPIDSource *visionPIDSource;

    DriveEncodersPIDSource *driveEncodersPIDSource;  //average of two drive encoders
    VisionController *vision;

 private:
    RobotModel *robot;
    RemoteControl *humanControl;
    double testVariable;
    double test2Variable;bool reachedSetpoint;
    double angle;
    double leftEncoderStartDistance, rightEncoderStartDistance;
    double turn_start_time;
    double P;
    double I;
    double D;bool turning;
    RobotDrive *driveTrain;
    uint32_t m_stateVal;
    uint32_t nextState;
    double m_maximumOutput;    // |maximum output|
    double m_minimumOutput;    // |minimum output|
    double m_maximumInput;       // maximum input - limit setpoint to this
    double m_minimumInput;       // minimum input - limit setpoint to this
    bool m_continuous;  // do the endpoints wrap around? eg. Absolute encoder
    double m_totalError;  //the sum of the errors for use in the integral calc
    double m_setpoint;
    double m_error;
    double m_result;
    double m_last_input = NAN;
    double m_prevError; // the prior sensor input (used to compute velocity)
};

#endif
