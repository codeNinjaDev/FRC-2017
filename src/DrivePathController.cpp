/*
 * DrivePathController.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: kidco
 */

#include <DrivePathController.h>
#include "TrajectoryMath.h"
DrivePathController::DrivePathController(Path* path) {
    init();
    LoadProfile(path->GetLeftWheelTrajectory(), path->GetRightWheelTrajectory(),
                1.0, 0.0);
    //TODO Add Constant
    kTurn = -0.0;

}
bool DrivePathController::OnTarget() {
    return followerLeft->IsFinishedTrajectory();
}

void DrivePathController::init() {
    //TODO Constants
    //followerLeft->Configure(0.0, 0.0, 0.0, 0.0,0.00.0, );
    //followerRight->Configure(0.0, 0.0, 0.0, 0.0,0.00.0, );

}
void DrivePathController::LoadProfile(Trajectory* leftProfile,
                                      Trajectory* rightProfile,
                                      double direction, double heading) {
    Reset();
    //followerLeft->SetGoal(leftProfile);
    //followerRight->SetTrajectory(rightProfile);
    this->direction = direction;
    this->heading = heading;

}

void DrivePathController::LoadProfileNoReset(Trajectory* leftProfile,
                                             Trajectory* rightProfile) {

    Reset();
    //followerLeft->SetGoal(leftProfile, )
    //followerRight->SetGoal(rightProfile);

}

void DrivePathController::Reset() {
    followerLeft->Reset();
    followerRight->Reset();
}
int DrivePathController::GetFollowerCurrentSegmentNumber() {
    return followerLeft->GetNumSegments();
}
void DrivePathController::SetTrajectory(Trajectory* t) {
    this->trajectory = t;
}
double DrivePathController::GetGoal() {
    return 0;
}
DriveSignal* DrivePathController::Update(Pose* pose) {
    if (OnTarget()) {
    return new DriveSignal(0, 0);
    } else {
    double distanceL = direction * pose->GetLeftDistance();
    double distanceR = direction * pose->GetRightDistance();

    double speedLeft = direction * followerLeft->LegacyCalculate(distanceL);
    double speedRight = direction * followerRight->LegacyCalculate(distanceR);

    double goalHeading = followerLeft->GetHeading();
    double observedHeading = -pose->GetHeading();

    double angleDiffRads = TrajectoryMath::GetDifferenceInAngleRadians(observedHeading, goalHeading);
    double angleDiff = angleDiffRads* (180.0 / M_PI);

    double turn = kTurn * angleDiff;
    return new DriveSignal(speedLeft + turn, speedRight - turn);
    }
}

Pose* DrivePathController::GetCurrentSetpoint() {
    return new Pose(followerLeft->GetCurrentSegment()->pos, 0, 0,0, -followerLeft->GetHeading(), 0);
}
DrivePathController::~DrivePathController() {
    // TODO Auto-generated destructor stub
}

