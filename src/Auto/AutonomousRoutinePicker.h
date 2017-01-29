/*
 * AutonomousRoutinePicker.h
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTONOMOUSROUTINEPICKER_H_
#define SRC_AUTO_AUTONOMOUSROUTINEPICKER_H_


#include "Auto/Routines/DriveForwardRoutine.h"
#include "Auto/Routines/DoNothingRoutine.h"
#include "SmartDashboard/SendableChooser.h"
#include "AutoRoutine.h"
#include <iostream>
using namespace std;
using namespace frc;



class AutonomousRoutinePicker {
public:
        AutonomousRoutinePicker();

        void ListOptions();
        AutoRoutine* Pick();
        void RegisterAutonomous(AutoRoutine* autonomous);
        AutoRoutine* GetAutoRoutine();

        virtual ~AutonomousRoutinePicker();
private:
        SendableChooser<int> autoChooser;

        vector<AutoRoutine>* autoRoutines = new vector<AutoRoutine>();
        void SetAutoRoutineByIndex(unsigned int input);
        int selectedIndex = 0;
};

#endif /* SRC_AUTO_AUTONOMOUSROUTINEPICKER_H_ */
