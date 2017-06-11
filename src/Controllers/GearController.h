/*
 * GearController.h
 *
 *  Created on: Mar 23, 2017
 *      Author: kidco
 */

#ifndef SRC_GEARCONTROLLER_H_
#define SRC_GEARCONTROLLER_H_
#include "../Hardware/RobotModel.h"
#include "../Hardware/ControlBoard.h"
#include "WPILib.h"
#include "../PID/AnalogPIDSource.h"
#include "../PID/AnalogPIDOutput.h"
class GearController {
 public:
    GearController(RobotModel* robot, RemoteControl* humanControl);
    PIDOutput* gearTilterPIDOutput;
    PIDController* gearTilterPID;

    AnalogPIDSource* gearTilterPIDSource;

    void Reset();
    void Update();
    void GearPIDUp(); //peg pid position
    void GearRest(); //threshold till past point for ramp
    void GearPIDRamp(); //PID for ramp intake
    void GearDown(); //threshold till past point for down position

    void SoftDisablePID();
    enum GearState {
        kInitialize, kTeleop
    };
    virtual ~GearController();

 private:
    RobotModel* robot;
    bool wasDown, wasUp, wasRest, wasRamp, toggleManual;
    RemoteControl* humanControl;

    uint32_t m_stateVal;
    uint32_t nextState;
};

#endif /* SRC_GEARCONTROLLER_H_ */
