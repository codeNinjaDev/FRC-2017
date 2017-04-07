/*
 * Path.h
 *
 *  Created on: Apr 5, 2017
 *      Author: kidco
 */

#ifndef PATH_H_
#define PATH_H_
#include "Trajectory.h"
class Path {
 protected:
    Trajectory::Pair* go_left_pair;
    string name;
    bool go_left;
 public:
    Path(string name, Trajectory::Pair* go_left_pair);
    string GetName();
    void GoLeft();
    void GoRight();
    Trajectory* GetLeftWheelTrajectory();
    Trajectory* GetRightWheelTrajectory();
    bool CanFlip(int segmentNum);
    double GetEndHeading();
    virtual ~Path();
};

#endif /* PATH_H_ */
