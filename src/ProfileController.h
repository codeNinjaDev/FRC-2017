/*
 * ProfileController.h
 *
 *  Created on: Apr 6, 2017
 *      Author: kidco
 */

#ifndef SRC_PROFILECONTROLLER_H_
#define SRC_PROFILECONTROLLER_H_
#include "DriveSignal.h"
#include "Pose.h"

class ProfileController {
 public:
    virtual DriveSignal* Update(Pose* pose) = 0;
    virtual Pose* GetCurrentSetpoint() = 0;
    virtual bool OnTarget() = 0;
};

#endif /* SRC_PROFILECONTROLLER_H_ */
