/*
 * TrajectoryMath.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: peter
 */

#include <TrajectoryMath.h>

static double TrajectoryMath::boundAngleNegPiToPiRadians(double angle) {
        // Naive algorithm
        while (angle >= M_PI) {
            angle -= 2.0 * M_PI;
        }
        while (angle < -M_PI) {
            angle += 2.0 * M_PI;
        }
        return angle;
    }

