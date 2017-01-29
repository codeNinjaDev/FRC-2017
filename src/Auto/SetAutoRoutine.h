/*
 * SetAutoRoutine.h
 *
 *  Created on: Jan 28, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_SETAUTOROUTINE_H_
#define SRC_AUTO_SETAUTOROUTINE_H_

#include "AutoRoutine.h"



class SetAutoRoutine {
public:

  //void function NOT constructor
  void setAutoRoutine(AutoRoutine* new_auto_routine);
  void start();
  void stop();
  void run();
  virtual ~SetAutoRoutine();

private:
  AutoRoutine* m_auto_routine;

};

#endif /* SRC_AUTO_SETAUTOROUTINE_H_ */
