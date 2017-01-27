/*
 * DoNothingRoutine.h
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_DONOTHINGROUTINE_H_
#define SRC_AUTO_ROUTINES_DONOTHINGROUTINE_H_

#include "Auto/AutoRoutine.h"

class DoNothingRoutine : public AutoRoutine {
public:
	void prestart();
protected:
	void routine();
};

#endif /* SRC_AUTO_ROUTINES_DONOTHINGROUTINE_H_ */
