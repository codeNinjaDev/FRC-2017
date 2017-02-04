/*
 * AutonomousRoutinePicker.h
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTONOMOUSROUTINEPICKER_H_
#define SRC_AUTO_AUTONOMOUSROUTINEPICKER_H_


#include "Routines/DoNothingRoutine.h"
#include "Routines/DriveForwardRoutine.h"
#include "Routines/JustShoot.h"
#include "SmartDashboard/SendableChooser.h"
#include "AutoRoutine.h"
#include <iostream>
using namespace std;
using namespace frc;


class AutonomousRoutinePicker {

	int selectedIndex = 0;
public:
        AutonomousRoutinePicker();
        void ListOptions();
        AutoRoutine* Pick();
        void RegisterAutonomous(AutoRoutine* autonomous);
        AutoRoutine* GetAutoRoutine();

        virtual ~AutonomousRoutinePicker();
private:
        SendableChooser<std::string> *autoChooser;

        vector<AutoRoutine> *autoRoutines = new vector<AutoRoutine>();
        void SetAutoRoutineByIndex(int);

};

#endif /* SRC_AUTO_AUTONOMOUSROUTINEPICKER_H_ */
