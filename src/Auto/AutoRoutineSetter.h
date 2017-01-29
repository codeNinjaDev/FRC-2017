/*
 * AutoRoutineSetter.h
 *
 *  Created on: Jan 29, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTOROUTINESETTER_H_
#define SRC_AUTO_AUTOROUTINESETTER_H_

#include "AutoRoutine.h"

class AutoRoutineSetter {
public:

  //void function NOT constructor
  void setAutoRoutine(AutoRoutine* new_auto_routine);
  void Start();
  void Stop();
  void Run();
  virtual ~AutoRoutineSetter();

private:
  AutoRoutine* m_auto_routine;

};

#endif /* SRC_AUTO_AUTOROUTINESETTER_H_ */
