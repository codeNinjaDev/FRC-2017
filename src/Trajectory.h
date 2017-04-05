/*
 * Trajectory.h
 *
 *  Created on: Apr 4, 2017
 *      Author: peter
 */

#ifndef SRC_TRAJECTORY_H_
#define SRC_TRAJECTORY_H_
#include "TrajectoryMath.h"
#include <iostream>
#include <vector>
using namespace std;
class Trajectory {
 public:
    class Pair {
     public:
        Pair(Trajectory* left, Trajectory* right);
        Trajectory* left;
        Trajectory* right;
    };
    class Segment {
     public:
        double pos, vel, acc, jerk, heading, dt, x, y;
        Segment(double pos, double vel, double acc, double jerk, double heading,
                double dt, double x, double y);
        Segment(Segment* to_copy);
        Segment();

        string ToString();
    };
    vector<Segment*>* segments;
    bool inverted_y;
    Trajectory(int length);
    Trajectory(vector<Segment*>* segments);
    void SetInvertedY(bool inverted);
    int GetNumSegments();
    Segment* GetSegment(int index);
    void SetSegment(int index, Segment* segment);
    void Append(Trajectory* to_append);
    void Scale(double scaling_factor);
    Trajectory* Copy();
    string ToString();
    string ToStringProfile();
    string ToStringEulidean();
 private:
    vector<Segment*>* CopySegments(vector<Segment*>* tocopy);

};

#endif /* SRC_TRAJECTORY_H_ */
