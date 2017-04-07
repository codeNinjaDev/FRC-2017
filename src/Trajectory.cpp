/*
 * Trajectory.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: peter
 */

#include <Trajectory.h>
#include "TrajectoryMath.h"
Trajectory::Pair::Pair(Trajectory* left, Trajectory* right) {
    this->left = left;
    this->right = right;
}

Trajectory::Segment::Segment(double pos, double vel, double acc, double jerk,
                             double heading, double dt, double x, double y) {
    this->pos = pos;
    this->vel = vel;
    this->acc = acc;
    this->jerk = jerk;
    this->heading = heading;
    this->dt = dt;
    this->x = x;
    this->y = y;
}

Trajectory::Segment::Segment() {

}

Trajectory::Segment::Segment(Segment* to_copy) {
    pos = to_copy->pos;
    vel = to_copy->vel;
    acc = to_copy->acc;
    jerk = to_copy->jerk;
    heading = to_copy->heading;
    dt = to_copy->dt;
    x = to_copy->x;
    y = to_copy->y;

}
string Trajectory::Segment::ToString() {

    return "pos: " + to_string(pos) + "; vel: " + to_string(vel) + "; acc: "
            + to_string(acc) + "; jerk: " + to_string(jerk) + "; heading: "
            + to_string(heading);
}
Trajectory::Trajectory(int length) {
    segments = new vector<Segment*>();
    for (int i = 0; i < length; ++i) {
    segments->at(i) = new Segment();
    }
}

Trajectory::Trajectory(vector<Segment*>* segments) {
    this->segments = segments;
}

void Trajectory::SetInvertedY(bool inverted) {
    inverted_y = inverted;
}

int Trajectory::GetNumSegments() {
    return segments->size();
}

Trajectory::Segment* Trajectory::GetSegment(int index) {
    if (index < GetNumSegments()) {
    if (!inverted_y) {
    return segments->at(index);
    } else {
    Segment* segment = new Segment(segments->at(index));
    segment->y *= -1.0;
    segment->heading = TrajectoryMath::BoundAngle0to2PiRadians(
            2 * M_PI - segment->heading);
    return segment;
    }
    } else {
    return new Segment();
    }
}

void Trajectory::SetSegment(int index, Segment* segment) {
    if (index < GetNumSegments()) {
    segments->at(index) = segment;
    }
}

void Trajectory::Scale(double scaling_factor) {
    for (int i = 0; i < GetNumSegments(); ++i) {
    segments->at(i)->pos *= scaling_factor;
    segments->at(i)->vel *= scaling_factor;
    segments->at(i)->acc *= scaling_factor;
    segments->at(i)->jerk *= scaling_factor;
    }
}
void Trajectory::Append(Trajectory* to_append) {
    vector<Segment*>* temp = new vector<Segment*>(
            GetNumSegments() + to_append->GetNumSegments());
    for (int i = 0; i < GetNumSegments(); ++i) {
    temp->at(i) = new Segment(segments->at(i));
    }
    for (int i = 0; i < to_append->GetNumSegments(); ++i) {
    temp->at(i + GetNumSegments()) = new Segment(to_append->GetSegment(i));
    }
    this->segments = temp;
}

Trajectory* Trajectory::Copy() {
    Trajectory* cloned = new Trajectory(GetNumSegments());
    cloned->segments = CopySegments(this->segments);
    return cloned;
}

vector<Trajectory::Segment*>* Trajectory::CopySegments(vector<Trajectory::Segment*>* tocopy) {
    vector<Segment*>* copied = new vector<Trajectory::Segment*>(tocopy->size());
    for (int i = 0; i < tocopy->size(); ++i) {
    copied->at(i) = new Segment(tocopy->at(i));
    }
    return copied;
}

string Trajectory::ToString() {
    string str = "Segment\tPos\tVel\tAcc\tJerk\tHeading\n";
    for (int i = 0; i < GetNumSegments(); ++i) {
    Trajectory::Segment* segment = GetSegment(i);
    str += i + "\t";
    str += to_string(segment->pos) + "\t";
    str += to_string(segment->vel) + "\t";
    str += to_string(segment->acc) + "\t";
    str += to_string(segment->jerk) + "\t";
    str += to_string(segment->heading) + "\t";
    str += "\n";
    }

    return str;
}

string Trajectory::ToStringProfile() {
    return ToString();
}
string Trajectory::ToStringEulidean() {
    string str = "Segment\tx\ty\tHeading\n";

    for (int i = 0; i < GetNumSegments(); ++i) {
        Trajectory::Segment* segment = GetSegment(i);
        str += i + "\t";
        str += to_string(segment->pos) + "\t";
        str += to_string(segment->vel) + "\t";
        str += to_string(segment->acc) + "\t";
        str += to_string(segment->jerk) + "\t";
        str += to_string(segment->heading) + "\t";
        str += "\n";
    }
    return str;
}
