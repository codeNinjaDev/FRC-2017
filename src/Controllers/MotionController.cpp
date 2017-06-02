/*
 * MotionController.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: mikec
 */

#include "MotionController.h"
#include <pathfinder.h>
#include "WPILib.h"

MotionController::MotionController() {

	Waypoint points[POINT_LENGTH];

	p1 = { -4, -1, d2r(45) };      // Waypoint @ x=-4, y=-1, exit angle= 45 degrees
	p2 = { -1, 2, 0 };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians
	p3 = {  2, 4, 0 };             // Waypoint @ x= 2, y= 4, exit angle= 0 radians
	p4 = { -8, -3, d2r(45) };      // Waypoint @ x=-4, y=-1, exit angle= 45 degrees
	p5 = { -3, 8, 0 };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians
	p6 = {  7, 9, 0 };             // Waypoint @ x= 2, y= 4, exit angle= 0 radians

	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	points[4] = p5;
	points[5] = p6;

	// Prepare the Trajectory for Generation.
	//
	// Arguments:
	// Fit Function:        FIT_HERMITE_CUBIC or FIT_HERMITE_QUINTIC
	// Sample Count:        PATHFINDER_SAMPLES_HIGH (100 000)
	//                      PATHFINDER_SAMPLES_LOW  (10 000)
	//                      PATHFINDER_SAMPLES_FAST (1 000)
	// Time Step:           0.001 Seconds
	// Max Velocity:        15 m/s
	// Max Acceleration:    10 m/s/s
	// Max Jerk:            60 m/s/s/s
	SmartDashboard::PutNumber("MOTION_STATE", 0);
	pathfinder_prepare(points, POINT_LENGTH, FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_LOW, 0.02, 15.0, 10.0, 60.0, &candidate);

	length = candidate.length;
	SmartDashboard::PutNumber("MOTION_STATE", 1);

	// Array of Segments (the trajectory points) to store the trajectory in
	trajectory = (Segment *)malloc(length * sizeof(Segment));

	SmartDashboard::PutNumber("MOTION_STATE", 2);
	// Generate the trajectory
	pathfinder_generate(&candidate, trajectory);
	SmartDashboard::PutNumber("MOTION_STATE", 3);

	Segment leftTrajectory[length];
	Segment rightTrajectory[length];

	// Generate the Left and Right trajectories of the wheelbase using the
	// originally generated trajectory
	pathfinder_modify_tank(trajectory, length, leftTrajectory, rightTrajectory, wheelbase_width);
	SmartDashboard::PutNumber("MOTION_STATE", 4);

	// Arg 1: The EncoderConfig
	// Arg 2: The EncoderFollower for this side
	// Arg 3: The Trajectory generated from `pathfinder_modify_tank`
	// Arg 4: The Length of the Trajectory (length used in Segment seg[length];)
	// Arg 5: The current value of your encoder
	//double l = pathfinder_follow_encoder(leftConfig, &leftFollower, leftTrajectory, trajectory_length, l_encoder_value);
	//double r = pathfinder_follow_encoder(rightConfig, &rightFollower, rightTrajectory, trajectory_length, r_encoder_value);
}

