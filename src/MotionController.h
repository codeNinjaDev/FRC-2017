/*
 * MotionController.h
 *
 *  Created on: Apr 8, 2017
 *      Author: mikec
 */

#ifndef SRC_MOTIONCONTROLLER_H_
#define SRC_MOTIONCONTROLLER_H_

#include <pathfinder.h>

class MotionController {
public:
	MotionController();

	int POINT_LENGTH = 6;
	double wheelbase_width = 0.6;

private:
	Waypoint p1;
	Waypoint p2;
	Waypoint p3;
	Waypoint p4;
	Waypoint p5;
	Waypoint p6;

	int length;

	Segment *trajectory;

	TrajectoryCandidate candidate;
};

#endif /* SRC_MOTIONCONTROLLER_H_ */
