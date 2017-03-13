/*
 * ShootPIDAction.h
 *
 *  Created on: Jan 30, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ACTION_SHOOTPIDACTION_H_
#define SRC_AUTO_ACTION_SHOOTPIDACTION_H_
#include "Action.h"
#include "Timer.h"
#include "../../Params.h"
#include "../../RobotModel.h"
#include "../../ShooterController.h"
class ShootPIDAction: public Action {
public:
	ShootPIDAction(RobotModel* robot, ShooterController* shooter, double timeout);

	bool IsFinished();
	void Update();
	void Done();
	void Start();
	virtual ~ShootPIDAction();
protected:

private:
	double speed, timeout, P, I, D;
	RobotModel* robot;
	ShooterController* shooter;
	bool reachedRPM;
};

#endif /* SRC_AUTO_ACTION_ShootPIDAction_H_ */
