#include "Params.h"
#include "DriveController.h"
#include "WPILib.h"

DriveController::DriveController(RobotModel *myRobot,
                                 RemoteControl *myHumanControl,
                                 VisionController *myVision) {
    robot = myRobot;
    vision = myVision;
    humanControl = myHumanControl;
    driveTrain = new RobotDrive(robot->leftDriveMotorA, robot->leftDriveMotorB,
                                robot->rightDriveMotorA,
                                robot->rightDriveMotorB);
    driveTrain->SetSafetyEnabled(false);

    robot->leftDriveEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
    robot->leftDriveEncoder->SetSamplesToAverage(DRIVE_Y_PID_SAMPLES_AVERAGE);

    robot->rightDriveEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
    robot->rightDriveEncoder->SetSamplesToAverage(DRIVE_Y_PID_SAMPLES_AVERAGE);

    leftPIDOutput = new WheelsPIDOutput(robot, robot->LeftWheels);
    leftPID = new PIDController(0.0, 0.0, 0.0, robot->leftDriveEncoder,
                                leftPIDOutput);
    leftPID->SetOutputRange(-1.0, 1.0);
    leftPID->SetAbsoluteTolerance(0.25);
    leftPID->Disable();

    rightPIDOutput = new WheelsPIDOutput(robot, robot->RightWheels);
    rightPID = new PIDController(0.0, 0.0, 0.0, robot->rightDriveEncoder,
                                 rightPIDOutput);
    rightPID->SetOutputRange(-1.0, 1.0);
    rightPID->SetAbsoluteTolerance(0.25);
    rightPID->Disable();

    visionPIDSource = new VisionPIDSource(vision);
    driveXPIDOutput = new DriveRotateMotorsPIDOutput(driveTrain);
    visionPID = new PIDController(0.0, 0.0, 0.0, visionPIDSource,
                                  driveXPIDOutput);
    visionPID->SetOutputRange(-1.0, 1.0);
    visionPID->SetAbsoluteTolerance(1);
    visionPID->Disable();
    turning = false;
    m_stateVal = kInitialize;
    nextState = kInitialize;
    //Cheezy Vars
    m_maximumOutput = 1.0;    // |maximum output|
    m_minimumOutput = -1.0;    // |minimum output|
    m_maximumInput = 0.0;       // maximum input - limit setpoint to this
    m_minimumInput = 0.0;       // minimum input - limit setpoint to this
    m_continuous = false;  // do the endpoints wrap around? eg. Absolute encoder
    m_prevError = 0.0;  // the prior sensor input (used to compute velocity)
    m_totalError = 0.0;  //the sum of the errors for use in the integral calc
    m_setpoint = 0.0;
    m_error = 0.0;
    m_result = 0.0;
}

DriveController::~DriveController() {
}

void DriveController::Update(double currTimeSec, double deltaTimeSec) {
    switch (m_stateVal) {
        case (kInitialize):
            visionPID->Disable();
            leftPID->Disable();
            rightPID->Disable();
            nextState = kTeleopDrive;
            break;
        case (kTeleopDrive):
            double driverLeftX;
            driverLeftX = humanControl->GetJoystickValue(
                    RemoteControl::kDriverJoy, RemoteControl::kLX);
            double driverLeftY;
            driverLeftY = humanControl->GetJoystickValue(
                    RemoteControl::kDriverJoy, RemoteControl::kLY);
            double driverRightX;
            driverRightX = humanControl->GetJoystickValue(
                    RemoteControl::kDriverJoy, RemoteControl::kRX);
            double driverRightY;
            driverRightY = humanControl->GetJoystickValue(
                    RemoteControl::kDriverJoy, RemoteControl::kRY);

            if (humanControl->GetArcadeDriveDesired()) {
            leftPID->Disable();
            rightPID->Disable();
            ArcadeDrive(driverLeftY, -driverRightX, true);
            } else {
            leftPID->Disable();
            rightPID->Disable();
            TankDrive(driverLeftY, driverRightY);
            }

            nextState = kTeleopDrive;
            break;
    }  // end of switch
    if (turning == true) {
    if (leftPID->OnTarget() && rightPID->OnTarget()) {
    reachedSetpoint = true;
    } else {
    reachedSetpoint = false;
    }
    }
    if ((Timer::GetFPGATimestamp() >= turn_start_time + .6)
            || reachedSetpoint) {
    leftPID->Disable();
    rightPID->Disable();
    Stop();
    turning = false;
    }
    m_stateVal = nextState;
}

void DriveController::ArcadeDrive(double myY, double myX, bool teleOp) {
    if (teleOp) {

    if ((humanControl->GetSlowDriveTier1Desired()
            && !humanControl->GetSlowDriveTier2Desired())
            || (!humanControl->GetSlowDriveTier1Desired()
                    && humanControl->GetSlowDriveTier2Desired())) {
    GLOBAL_DRIVE_SPEED_MULTIPLIER = 0.65;
    SQUARE_DRIVE_AXIS_INPUT = false;
    } else if (humanControl->GetSlowDriveTier1Desired()
            && humanControl->GetSlowDriveTier2Desired()) {
    GLOBAL_DRIVE_SPEED_MULTIPLIER = 0.35;
    SQUARE_DRIVE_AXIS_INPUT = false;
    } else {
    GLOBAL_DRIVE_SPEED_MULTIPLIER = 1.0;
    SQUARE_DRIVE_AXIS_INPUT = true;
    }

    driveTrain->ArcadeDrive(
            myY * GLOBAL_DRIVE_SPEED_MULTIPLIER * HARDSET_DRIVE_SPEED_MAX,
            myX * GLOBAL_DRIVE_SPEED_MULTIPLIER * HARDSET_DRIVE_SPEED_MAX,
            SQUARE_DRIVE_AXIS_INPUT);

    } else {
    driveTrain->ArcadeDrive(myY, myX, false);
    }
}

void DriveController::TankDrive(double myLeft, double myRight) {
    if (humanControl->GetReverseDriveDesired()) {
    myLeft = -myLeft;
    myRight = -myRight;
    }

    driveTrain->TankDrive(myLeft * GLOBAL_DRIVE_SPEED_MULTIPLIER,
                          myRight * GLOBAL_DRIVE_SPEED_MULTIPLIER,
                          SQUARE_DRIVE_AXIS_INPUT);
}

void DriveController::Reset() {
    m_stateVal = kInitialize;
}

void DriveController::Stop() {
    driveTrain->ArcadeDrive(0.00, 0.00, false);
    turning = false;
}

void DriveController::TurnAngle(double angle) {
    //coverted into encoder rev
    turning = true;
    this->angle = (angle * 40.0) / (180.0);
    leftEncoderStartDistance, rightEncoderStartDistance = 0.0;
    turn_start_time = Timer::GetFPGATimestamp();

    robot->leftDriveEncoder->Reset();
    robot->rightDriveEncoder->Reset();

    leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
    rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();

    leftPID->SetOutputRange(-0.6, 0.6);
    leftPID->SetPID(P, I, D);
    leftPID->SetSetpoint(angle + leftEncoderStartDistance);

    rightPID->SetOutputRange(-0.6, 0.6);
    rightPID->SetPID(P, I, D);
    rightPID->SetSetpoint(-1.0 * (angle + rightEncoderStartDistance));

    leftPID->Enable();
    rightPID->Enable();
}

double DriveController::CheezyCalculate(double input) {
    m_last_input = input;
            m_error = m_setpoint - input;
            if (m_continuous) {
                if (fabs(m_error) >
                        (m_maximumInput - m_minimumInput) / 2) {
                    if (m_error > 0) {
                        m_error = m_error - m_maximumInput + m_minimumInput;
                    } else {
                        m_error = m_error +
                                m_maximumInput - m_minimumInput;
                    }
                }
            }

            if ((m_error * P < m_maximumOutput) &&
                    (m_error * P > m_minimumOutput)) {
                m_totalError += m_error;
            } else {
                m_totalError = 0;
            }

            m_result = (P * m_error + I * m_totalError + D * (m_error - m_prevError));
            m_prevError = m_error;

            if (m_result > m_maximumOutput) {
                m_result = m_maximumOutput;
            } else if (m_result < m_minimumOutput) {
                m_result = m_minimumOutput;
            }
            return m_result;
}
