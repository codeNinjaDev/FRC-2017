/*
 * Auto.h
 *
 *  Created on: Jan 28, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTO_H_
#define SRC_AUTO_AUTO_H_
#include "SetAutoRoutine.h"
#include "AutonomousRoutinePicker.h"
#include "AutoRoutine.h"


class Auto {
public:
  AutoRoutine* autoRoutine;

  void listOptions();
  void start();
  void stop();

  virtual ~Auto();
private:


};

#endif /* SRC_AUTO_AUTO_H_ */
