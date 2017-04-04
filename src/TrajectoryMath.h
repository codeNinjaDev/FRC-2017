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
     static double getDifferenceInAngleRadians(double from, double to) {
        return boundAngleNegPiToPiRadians(to - from);
    }

    /**
     * Get the difference in angle between two angles.
     *
     * @param from The first angle
     * @param to   The second angle
     * @return The change in angle from the first argument necessary to line up
     * with the second. Always between -180 and 180
     */
     static double getDifferenceInAngleDegrees(double from, double to) {
        return boundAngleNeg180to180Degrees(to - from);
    }

     static double boundAngle0to360Degrees(double angle) {
        // Naive algorithm
        while (angle >= 360.0) {
            angle -= 360.0;
        }
        while (angle < 0.0) {
            angle += 360.0;
        }
        return angle;
    }

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

     static double boundAngle0to2PiRadians(double angle) {
        // Naive algorithm
        while (angle >= 2.0 * M_PI) {
            angle -= 2.0 * M_PI;
        }
        while (angle < 0.0) {
            angle += 2.0 * M_PI;
        }
        return angle;
    }

     static double boundAngleNegPiToPiRadians(double angle) {
        // Naive algorithm
        while (angle >= M_PI) {
            angle -= 2.0 * M_PI;
        }
        while (angle < -M_PI) {
            angle += 2.0 * M_PI;
        }
        return angle;
    }

};

#endif /* SRC_TRAJECTORYMATH_H_ */
