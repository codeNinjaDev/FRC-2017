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
#include "AutoWidget.h"
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
        AutoWidget *autoChooser;

        vector<AutoRoutine>* autoRoutines = new vector<AutoRoutine>();
        void SetAutoRoutineByIndex(int input);
        int selectedIndex = 0;
};

#endif /* SRC_AUTO_AUTONOMOUSROUTINEPICKER_H_ */
