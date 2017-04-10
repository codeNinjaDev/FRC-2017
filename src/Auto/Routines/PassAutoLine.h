/*
 * PassAutoLine.h
 *
 *  Created on: Mar 11, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_PASSAUTOLINE_H_
#define SRC_AUTO_ROUTINES_PASSAUTOLINE_H_
#include "LightsController.h"
#include "../AutoRoutine.h"
class PassAutoLine : public AutoRoutine {
 public:
    PassAutoLine(MasterController* controller);
    void Prestart();

   private:
    DriveController *driveTrain;
    RobotModel *robot;
    LightsController* lights;
    GearController* gearController;
   protected:
    void Routine();
};



#endif /* SRC_AUTO_ROUTINES_PASSAUTOLINE_H_ */
