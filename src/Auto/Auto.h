/*
 * Auto.h
 *
 *  Created on: Jan 28, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTO_H_
#define SRC_AUTO_AUTO_H_
#include "AutonomousRoutinePicker.h"
#include "AutoRoutine.h"
#include "AutoRoutineSetter.h"



class Auto {
public:
  AutoRoutine* autoRoutine;

  void ListOptions();
  void Start();
  void Stop();

  virtual ~Auto();
private:


};

#endif /* SRC_AUTO_AUTO_H_ */
