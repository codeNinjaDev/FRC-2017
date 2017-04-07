/*
 * Pose.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: kidco
 */

#include <Pose.h>
#include <typeinfo>
Pose::Pose(double leftDistance, double rightDistance, double leftVelocity,
           double rightVelocity, double heading, double headingVelocity) {
    this->leftDistance = leftDistance;
    this->rightDistance = rightDistance;
    this->leftVelocity = leftVelocity;
    this->rightVelocity = rightVelocity;
    this->heading = heading;
    this->headingVelocity = headingVelocity;

}
void Pose::Reset(double leftDistance, double rightDistance, double leftVelocity,
                 double rightVelocity, double heading, double headingVelocity) {
    this->leftDistance = leftDistance;
    this->rightDistance = rightDistance;
    this->leftVelocity = leftVelocity;
    this->rightVelocity = rightVelocity;
    this->heading = heading;
    this->headingVelocity = headingVelocity;

}
double Pose::GetLeftDistance() {
    return leftDistance;
}
double Pose::GetHeading() {
    return heading;
}
double Pose::GetRightDistance() {
    return rightDistance;
}
double Pose::GetLeftVelocity() {
    return leftVelocity;
}
double Pose::GetRightVelocity() {
    return rightVelocity;
}
double Pose::GetHeadingVelocity() {
    return headingVelocity;
}
Pose::RelativePoseGenerator::RelativePoseGenerator() {
    //m_base_pose = ;
}
Pose* Pose::RelativePoseGenerator::Get(Pose* pose) {
    return new Pose(
            pose->GetLeftDistance() - m_base_pose->GetLeftDistance(),
            pose->GetRightDistance() - m_base_pose->GetRightDistance(),
            m_base_pose->GetLeftVelocity() - pose->GetLeftVelocity(),
            m_base_pose->GetRightVelocity() - pose->GetRightVelocity(),
            pose->GetHeading() - m_base_pose->GetHeading(),
            m_base_pose->GetHeadingVelocity() - pose->GetHeadingVelocity());
}
template <typename T>

bool Pose::Equals(T) {
    if(!(typeid(T) == typeid(Pose*))) {
        return false;
    }

    if(typeid(T) == typeid(this)) {
        return true;
    }
    Pose* other_pose = new Pose(0, 0, 0, 0, 0, 0);
    return other_pose->GetLeftDistance() == GetLeftDistance()
                    && other_pose->GetRightDistance() == GetRightDistance()
                    && other_pose->GetLeftVelocity() == GetLeftVelocity()
                    && other_pose->GetRightVelocity() == GetRightVelocity()
                    && other_pose->GetHeading() == GetHeading()
                    && other_pose->GetHeadingVelocity() == GetHeadingVelocity();
    //Pose* other_pose = (Pose)*T;

}

Pose::~Pose() {
    // TODO Auto-generated destructor stub
}

