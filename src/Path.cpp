/*
 * Path.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: kidco
 */

#include "Path.h"

Path::Path(string name, Trajectory::Pair* go_left_pair) {
    this->go_left_pair = go_left_pair;
    this->name = name;
    go_left = true;
}

string Path::GetName() {
    return name;
}
;
void Path::GoLeft() {
    go_left = true;
    go_left_pair->left->SetInvertedY(false);
    go_left_pair->right->SetInvertedY(false);

}
void Path::GoRight() {
    go_left = true;
    go_left_pair->left->SetInvertedY(true);
    go_left_pair->right->SetInvertedY(true);

}

Trajectory* Path::GetLeftWheelTrajectory() {
    return ((go_left == true) ? go_left_pair->left : go_left_pair->right);
}
Trajectory* Path::GetRightWheelTrajectory() {
    return ((go_left == true) ? go_left_pair->right : go_left_pair->left);
}

bool Path::CanFlip(int segmentNum) {
    Trajectory::Segment* a = go_left_pair->right->GetSegment(segmentNum);
    Trajectory::Segment* b = go_left_pair->left->GetSegment(segmentNum);

    return (a->pos == b->pos) && (a->vel == b->vel);
}
double Path::GetEndHeading() {
    int numSegments = GetLeftWheelTrajectory()->GetNumSegments();
    Trajectory::Segment* lastSegment = GetLeftWheelTrajectory()->GetSegment(numSegments - 1);
    return lastSegment->heading;
}
Path::~Path() {
    // TODO Auto-generated destructor stub
}

