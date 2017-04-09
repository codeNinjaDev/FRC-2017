/*
 * CenterGear.h
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ROUTINES_CENTERGEAR_H_
#define SRC_AUTO_ROUTINES_CENTERGEAR_H_

#include "../AutoRoutine.h"
#include "../../LightsController.h"

class CenterGear : public AutoRoutine {
 public:
    CenterGear(VisionController* vision, RobotModel* robot,
               DriveController* driveTrain, Profile* profile, GearController* gearController, LightsController* lights);

  virtual ~CenterGear();
  void Prestart();

 private:
  DriveController *driveTrain;
  RobotModel *robot;
  VisionController *vision;
  LightsController* lights;
  GearController* gearController;
  Profile* profile;
 protected:
  void Routine();
};


#endif /* SRC_AUTO_ROUTINES_CENTERGEAR_H_ */
