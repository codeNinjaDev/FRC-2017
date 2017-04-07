/*
 * DriveStraightController.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: kidco
 */

#include <DriveStraightController.h>

DriveStraightController::DriveStraightController(Pose* priorSetpoint,
                                                 double goalSetpoint,
                                                 double maxVelocity,
                                                 DriveController* driveTrain) {
    TrajectoryFollower::TrajectoryConfig* config =
            new TrajectoryFollower::TrajectoryConfig();
    //TODO Constants
    config->dt = 0.0;
    config->max_acc = 0.0;
    config->max_vel = 0.0;
    this->driveTrain = driveTrain;
    mDistanceController = new TrajectoryFollowingPositionController(0.0, 0.0,
                                                                    0.0, 0.0,
                                                                    0.0, 0.0,
                                                                    config);
    TrajectoryFollower::TrajectorySetPoint* initialSetpoint =
            new TrajectoryFollower::TrajectorySetPoint();
    initialSetpoint->pos = encoderDistance(priorSetpoint);
    initialSetpoint->vel = encoderVelocity(priorSetpoint);
    mDistanceController->SetGoal(initialSetpoint, goalSetpoint);
    driveTrain->TurnAngle(priorSetpoint->GetHeading());
    //TODO Constants
    mSetpointRelativePose = new Pose(priorSetpoint->GetLeftDistance(),
                                     priorSetpoint->GetRightDistance(), 0, 0,
                                     priorSetpoint->GetHeading(),
                                     priorSetpoint->GetHeadingVelocity());

}
DriveSignal* DriveStraightController::Update(Pose* currentPose) {
    mDistanceController->Update((
            currentPose->GetLeftDistance() + currentPose->GetRightDistance())
            / 2.0, (currentPose->GetLeftVelocity()
            + currentPose->GetRightVelocity()) / 2.0);
    double throttle = mDistanceController->Get();
    double turn = driveTrain->CheezyCalculate(currentPose->GetHeading());
    return new DriveSignal(throttle + turn, throttle - turn);
}
Pose* DriveStraightController::GetCurrentSetpoint() {
    TrajectoryFollower::TrajectorySetPoint* trajectorySetpoint = mDistanceController->GetSetPoint();
    double dist = trajectorySetpoint->pos;
    double velocity = trajectorySetpoint->vel;
    return new Pose(mSetpointRelativePose->GetLeftDistance() + dist, mSetpointRelativePose->GetRightDistance() + dist,mSetpointRelativePose->GetLeftVelocity() + velocity, mSetpointRelativePose->GetRightVelocity() + velocity,mSetpointRelativePose->GetHeading(), mSetpointRelativePose->GetHeadingVelocity());
}
double DriveStraightController::encoderVelocity(Pose* pose) {
    return (pose->GetLeftVelocity() + pose->GetRightVelocity()) / 2.0;
}
double DriveStraightController::encoderDistance(Pose* pose) {
    return (pose->GetLeftDistance() + pose->GetRightDistance()) / 2.0;
}
bool DriveStraightController::OnTarget() {
    return mDistanceController->IsOnTarget();
}
DriveStraightController::~DriveStraightController() {
    // TODO Auto-generated destructor stub
}

