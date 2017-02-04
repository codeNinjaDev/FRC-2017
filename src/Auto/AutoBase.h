/*
 * AutoBase.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTOBASE_H_
#define SRC_AUTO_AUTOBASE_H_
#include "Action/Action.h"
#include "WPILib.h"
#include <iostream>
using namespace std;

class AutoBase {
	bool m_active;
	static constexpr double m_update_rate = (1.0/50.0);

	public:
		  AutoBase();
		  void Prestart();
		  void Run();
		  void Stop();
		  bool IsActive();
		  void RunAction(Action* action); /*throw AutoRoutineEndedException*/

		  //bool isActiveWithThrow() throw AutoRoutineEndedException;

    virtual ~AutoBase();
protected:
  virtual void Routine();
  //virtual void routine();

};

#endif /* SRC_AUTO_AUTOBASE_H_ */
