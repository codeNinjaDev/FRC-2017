/*
 * MasterController.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: kidco
 */

#include <MasterController.h>

MasterController::MasterController(VisionController* vision, RobotModel* robot,
                                   DriveController* driveTrain, GearController* gearController,
                                   MotionController* motion, LightsController* lights) {
    this->vision = vision;
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->gearController = gearController;
    this->motion = motion;
    this->lights = lights;
}

VisionController* MasterController::GetVisionController() {
    return vision;
}

RobotModel* MasterController::GetRobotModel() {
    return robot;
}

DriveController* MasterController::GetDriveController() {
    return driveTrain;
}
GearController* MasterController::GetGearController() {
    return gearController;
}
MotionController* MasterController::GetMotionController() {
    return motion;
}
LightsController* MasterController::GetLightsController() {
    return lights;
}

