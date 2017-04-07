/*
 * TurnInPlaceController.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: kidco
 */

#include <TurnInPlaceController.h>

TurnInPlaceController::TurnInPlaceController(Pose* poseToContinueFrom, double destHeading, double velocity) {
    //TODO Constants
    TrajectoryFollower::TrajectoryConfig* config = new TrajectoryFollower::TrajectoryConfig();
    config->dt = 0.0;
    config->max_acc = 0.0;
    config->max_vel = 0.0;
    mController = new TrajectoryFollowingPositionController(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, config);
    TrajectoryFollower::TrajectorySetPoint* initialSetpoint = new TrajectoryFollower::TrajectorySetPoint();
    initialSetpoint->pos = poseToContinueFrom->GetHeading();
    initialSetpoint->vel = poseToContinueFrom->GetHeadingVelocity();
    mController->SetGoal(initialSetpoint, destHeading);
    mSetpointRelativePose = poseToContinueFrom;
}

DriveSignal* TurnInPlaceController::Update(Pose* pose) {
    mController->Update(pose->GetHeading(), pose->GetHeadingVelocity());
    double turn = mController->Get();
    return new DriveSignal(turn, -turn);
}

Pose* TurnInPlaceController::GetCurrentSetpoint() {
    TrajectoryFollower::TrajectorySetPoint* setpoint = mController->GetSetPoint();
    return new Pose(mSetpointRelativePose->GetLeftDistance(), mSetpointRelativePose->GetRightDistance(), mSetpointRelativePose->GetLeftVelocity(), mSetpointRelativePose->GetRightVelocity(), setpoint->pos, setpoint->vel);
}
bool TurnInPlaceController::OnTarget() {
    return mController->IsOnTarget();

}

double TurnInPlaceController::GetHeadingGoal() {
    return mController->GetGoal();
}
TurnInPlaceController::~TurnInPlaceController() {
    // TODO Auto-generated destructor stub
}

