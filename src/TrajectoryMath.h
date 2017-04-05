/*
 * TrajectoryMath.h
 *
 *  Created on: Apr 4, 2017
 *      Author: peter
 */

#ifndef SRC_TRAJECTORYMATH_H_
#define SRC_TRAJECTORYMATH_H_
#include <math.h>

class TrajectoryMath {
 public:

    /**
     * Get the difference in angle between two angles.
     *
     * @param from The first angle
     * @param to   The second angle
     * @return The change in angle from the first argument necessary to line up
     * with the second. Always between -Pi and Pi
     */
    static double getDifferenceInAngleRadians(double from, double to);
    /**
     * Get the difference in angle between two angles.
     *
     * @param from The first angle
     * @param to   The second angle
     * @return The change in angle from the first argument necessary to line up
     * with the second. Always between -180 and 180
     */
    static double getDifferenceInAngleDegrees(double from, double to);

    static double boundAngle0to360Degrees(double angle);

    static double boundAngleNeg180to180Degrees(double angle) {
        // Naive algorithm
        while (angle >= 180.0) {
        angle -= 360.0;
        }
        while (angle < -180.0) {
        angle += 360.0;
        }
        return angle;
    }

    static double boundAngle0to2PiRadians(double angle);

    static double boundAngleNegPiToPiRadians(double angle);

};

#endif /* SRC_TRAJECTORYMATH_H_ */
