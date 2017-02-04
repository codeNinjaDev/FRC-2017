/*
 * JustShoot.h
 *
 *  Created on: Jan 30, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_JUSTSHOOT_H_
#define SRC_AUTO_ROUTINES_JUSTSHOOT_H_
#include "../AutoRoutine.h"
class JustShoot : public AutoRoutine {
public:
  void Prestart();
protected:
  void Routine();
};

#endif /* SRC_AUTO_ROUTINES_JUSTSHOOT_H_ */
