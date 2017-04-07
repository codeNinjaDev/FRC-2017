/*
 * Pose.h
 *
 *  Created on: Apr 5, 2017
 *      Author: kidco
 */

#ifndef SRC_POSE_H_
#define SRC_POSE_H_
#include <iostream>
#include <string>

using namespace std;
class Pose {
 public:

    Pose(double leftDistance, double rightDistance, double leftVelocity,
         double rightVelocity, double heading, double headingVelocity);
    double leftDistance, rightDistance, leftVelocity, rightVelocity, heading,
            headingVelocity;
    void Reset(double leftDistance, double rightDistance, double leftVelocity,
               double rightVelocity, double heading, double headingVelocity);
    double GetLeftDistance();
    double GetHeading();
    double GetRightDistance();
    double GetLeftVelocity();
    double GetRightVelocity();
    double GetHeadingVelocity();

    class RelativePoseGenerator {
     public:
        RelativePoseGenerator();
        Pose* Get(Pose* pose);
     private:
        Pose* m_base_pose;
    };
    template<typename T>

    bool Equals(T);

    virtual ~Pose();
};

#endif /* SRC_POSE_H_ */
