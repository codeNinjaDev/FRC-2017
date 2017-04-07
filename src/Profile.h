/*
 * Profile.h
 *
 *  Created on: Apr 6, 2017
 *      Author: kidco
 */

#ifndef SRC_PROFILE_H_
#define SRC_PROFILE_H_
#include "DrivePathController.h"
#include "DriveStraightController.h"
#include "TurnInPlaceController.h"
#include "Path.h"
#include "DriveController.h"
#include "WPILib.h"
#include "ProfileController.h"
class Profile {
 public:
    Profile(RobotModel* robot, DriveController* driveTrain);
    void SetDistanceSetpoint(double distance);
    void SetDistanceSetpoint(double distance, double velocity);
    void SetOpenLoop(DriveSignal* signal);
    void SetTurnSetPoint(double heading);
    void SetTurnSetPoint(double heading, double velocity);
    void Reset();
    void SetPathSetpoint(Path* path);
    void SetFinishLineSetpoint(double distance, double heading);
    void GetState();
    void Update();
    void SetDriveOutputs(DriveSignal* signal);
    Pose* GetPhysicalPose();
    bool ControllerOnTarget();
    void ReloadConstants();

    virtual ~Profile();
 protected:
    double m_inches_per_tick;
    double m_wheelbase_width;
    double m_turn_slip_factor;
 private:
    ProfileController* profileController = nullptr;
    Pose* m_cached_pose;
    Pose* GetPoseToContinueFrom(bool for_turn_controller);
    DriveController* driveTrain;
    RobotModel* robot;
};

#endif /* SRC_PROFILE_H_ */
