/*
 * Blank2.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#include "Blank2.h"

Blank2::Blank2(MasterController* controllers) {
    this->controllers = controllers;

}

void Blank2::Prestart() {
}
void Blank2::Routine() {
	DriveDistanceStraight(controllers, 27.0*12.0, 0.8, 9, false, false);
	WaitTime(1.0);
}

Blank2::~Blank2() {
	// TODO Auto-generated destructor stub
}

