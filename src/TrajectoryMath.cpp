/*
 * TrajectoryMath.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: peter
 */

#include <TrajectoryMath.h>

double TrajectoryMath::BoundAngleNegPiToPiRadians(double angle) {
    // Naive algorithm
    while (angle >= M_PI) {
    angle -= 2.0 * M_PI;
    }
    while (angle < -M_PI) {
    angle += 2.0 * M_PI;
    }
    return angle;
}
double TrajectoryMath::GetDifferenceInAngleDegrees(double from, double to) {
    return BoundAngleNeg180to180Degrees(to - from);
}

double TrajectoryMath::BoundAngle0to360Degrees(double angle) {
    // Naive algorithm
    while (angle >= 360.0) {
    angle -= 360.0;
    }
    while (angle < 0.0) {
    angle += 360.0;
    }
    return angle;
}

double TrajectoryMath::BoundAngle0to2PiRadians(double angle) {
    // Naive algorithm
    while (angle >= 2.0 * M_PI) {
    angle -= 2.0 * M_PI;
    }
    while (angle < 0.0) {
    angle += 2.0 * M_PI;
    }
    return angle;
}

