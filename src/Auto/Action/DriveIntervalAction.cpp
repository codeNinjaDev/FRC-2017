/*
 * DriveInterval.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */
#include "Timer.h"
#include "DriveIntervalAction.h"

DriveIntervalAction::DriveIntervalAction(Profile* profile, double timeout,
                                         double distance) {
    goal_time = timeout;
    this->distance = distance;

    this->profile = profile;
}
bool DriveIntervalAction::IsFinished() {
    Pose* pose = profile->GetPhysicalPose();
    double avg = (pose->GetLeftDistance() + pose->GetRightDistance()) / 2.0;
    bool is_positive = (distance > 0);
return ( is_positive ? avg >= distance : avg <= distance);
}

void DriveIntervalAction::Update() {
    SmartDashboard::PutNumber("reachedUPDATE", Timer::GetFPGATimestamp());

}

void DriveIntervalAction::Done() {
    profile->driveTrain->Stop();
}

void DriveIntervalAction::Start() {
    SmartDashboard::PutNumber("reachedSTART", Timer::GetFPGATimestamp());
    start_time = Timer::GetFPGATimestamp();
    profile->SetDistanceSetpoint(distance);
}
DriveIntervalAction::~DriveIntervalAction() {
    // TODO Auto-generated destructor stub
}

