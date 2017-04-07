/*
 * DriveSignal.h
 *
 *  Created on: Apr 5, 2017
 *      Author: kidco
 */

#ifndef SRC_DRIVESIGNAL_H_
#define SRC_DRIVESIGNAL_H_

class DriveSignal {
 public:
    double leftMotor;
    double rightMotor;
    DriveSignal(double leftMotor, double rightMotor);
    DriveSignal* NEUTRAl = new DriveSignal(0.0, 0.0);
;
    virtual ~DriveSignal();
};

#endif /* SRC_DRIVESIGNAL_H_ */
