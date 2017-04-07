/*
 * Profile.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: kidco
 */

#include <Profile.h>
#include "DriveStraightController.h"
#include "TurnInPlaceController.h"

Profile::Profile(RobotModel* robot, DriveController* driveTrain) {
    //Constants
    m_inches_per_tick = 0.0;
    m_wheelbase_width = 0.0;
    m_turn_slip_factor = 0.0;
    m_cached_pose = new Pose(0, 0, 0, 0, 0, 0);
    this->driveTrain = driveTrain;
    this->robot = robot;
}
void Profile::SetOpenLoop(DriveSignal* signal) {
    profileController = nullptr;
    SetDriveOutputs(signal);
}
void Profile::SetDistanceSetpoint(double distance) {
    //TODO Constants

    SetDistanceSetpoint(distance, 0.0);
}
void Profile::SetDistanceSetpoint(double distance, double velocity) {
    //TODO Constants
    double vel_to_use = 0;
    //double vel_to_use = Math.min(Constants.kDriveMaxSpeedInchesPerSec, Math.max(velocity, 0));
    profileController = new DriveStraightController(
            GetPoseToContinueFrom(false), distance, vel_to_use, driveTrain);
}

void Profile::SetTurnSetPoint(double heading) {
    //TODO Constants
    SetTurnSetPoint(heading, 0.0);
}
void Profile::SetTurnSetPoint(double heading, double velocity) {
    //TODO Constants
    double vel_to_use = 0;
    //double vel_to_use = Math.min(Constants.kDriveMaxSpeedInchesPerSec, Math.max(velocity, 0));
    profileController = new TurnInPlaceController(GetPoseToContinueFrom(false),
                                                  heading, vel_to_use);
}
void Profile::Reset() {
    robot->ResetEncoders();
}
void Profile::SetPathSetpoint(Path* path) {
    Reset();
    profileController = new DrivePathController(path);
}

void Profile::GetState() {
    Pose* setPointPose =
            profileController == nullptr ?
                    GetPhysicalPose() : profileController->GetCurrentSetpoint();
    SmartDashboard::PutNumber(
            "Drive_set_point Pos",
            DriveStraightController::encoderDistance(setPointPose));
    SmartDashboard::PutNumber("left_signal", robot->leftDriveMotorA->Get());
    SmartDashboard::PutNumber("right_signal", robot->rightDriveMotorA->Get());
    SmartDashboard::PutBoolean(
            "On_target",
            (profileController != nullptr && profileController->OnTarget()));
}
void Profile::Update() {
    if (profileController == nullptr) {
    return;
    }
    SetDriveOutputs(profileController->Update(GetPhysicalPose()));
}
void Profile::SetDriveOutputs(DriveSignal* signal) {
    robot->SetLeftMotors(signal->leftMotor);
    robot->SetRightMotors(-signal->rightMotor);

}

Pose* Profile::GetPoseToContinueFrom(bool for_turn_controller) {
    if ((!for_turn_controller)
            && (typeid(profileController) == typeid(TurnInPlaceController))) {
        Pose* pose_to_use = GetPhysicalPose();
        pose_to_use->heading = ((TurnInPlaceController*) profileController)->GetHeadingGoal();
        pose_to_use->headingVelocity = 0;
        return pose_to_use;
    } else if ((profileController == nullptr
            || (typeid(profileController) == typeid(DriveStraightController)))
            && for_turn_controller) {
        return GetPhysicalPose();
        /*} else if(typeid(profileController) == typeid(DriveFinishLineController)) {
        return GetPhysicalPose();
    */} else if(profileController->OnTarget()) {
        return profileController->GetCurrentSetpoint();
    } else {
        return GetPhysicalPose();
    }
}
Pose* Profile::GetPhysicalPose() {
    //TODO Gyro
    m_cached_pose->Reset(robot->leftDriveEncoder->GetDistance(), robot->rightDriveEncoder->GetDistance(), robot->leftDriveEncoder->GetRate(), robot->rightDriveEncoder->GetRate(), 0.0, 0.0);
    return m_cached_pose;
}
void Profile::ReloadConstants() {

}

bool Profile::ControllerOnTarget() {
    return (profileController != nullptr) && (profileController->OnTarget());
}
Profile::~Profile() {
    // TODO Auto-generated destructor stub
}

