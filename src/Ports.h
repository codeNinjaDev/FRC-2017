#ifndef PORTS_H
#define PORTS_H

// ***************** PWM PORTS *****************
static const int LEFT_DRIVE_MOTOR_A_PWM_PORT            = 0;
static const int LEFT_DRIVE_MOTOR_B_PWM_PORT            = 2;
static const int RIGHT_DRIVE_MOTOR_A_PWM_PORT           = 1;
static const int RIGHT_DRIVE_MOTOR_B_PWM_PORT           = 3;
static const int SHOOTER_MOTOR_PWM_PORT                 = 4;

// ***************** PDP CHANNELS *****************

static const int LEFT_DRIVE_MOTOR_A_PDP_CHAN           = 12;
static const int LEFT_DRIVE_MOTOR_B_PDP_CHAN           = 13;
static const int RIGHT_DRIVE_MOTOR_A_PDP_CHAN          = 14;
static const int RIGHT_DRIVE_MOTOR_B_PDP_CHAN          = 15;
static const int SHOOTER_MOTOR_PDP_CHAN                = 11;

// ***************** DIGITAL I/O PORTS *****************

// ******************* ANALOG IN PORTS*******************

// ***************** MISC *****************

// ***************** SOLENOID PORTS *****************

// ***************** JOYSTICK USB PORTS *****************
//MAKE SURE JOYSTICKS ARE SET TO "D" position on back

static const bool USING_WIN_DRIVER_STATION             = true;
static const int DRIVER_JOY_USB_PORT                   = 0;
static const int OPERATOR_JOY_USB_PORT                 = 1;
// ***************** BUTTONS *****************

//Controller button ports

static const int DRIVE_DIRECTION_BUTTON_PORT           = 9;
static const int SHOOTER_RUN_BUTTON_PORT               = 1;

#endif
