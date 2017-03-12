/*
 * MotorTest.c
 *
 * Created: 3/11/2017 5:47:58 PM
 * Author : Michael Humphrey
 */ 
 
#include <avr/io.h>		// I don't actually know
#include <util/delay.h>	// for _delay_ms()
#include "RSXAVRD.h"	// Drivers

// Speed to operate the motors, 0-100
#define SPEED 80

// Helpful constants
#define STEPS_PER_ROTATION 1600
#define DEGREES_PER_STEP .225

// Motor direction, 1=CCW 0=CW
#define CLOCKWISE 0
#define COUNTERCLOCKWISE 1

// Motor names
#define BASE_MOTOR 5
#define CAMERA_MOTOR 4
#define ARM_TILT_MOTOR 3
#define ARM_ROTATION_MOTOR 2
#define SHOULDER_MOTOR 1
#define ELBOW_MOTOR 0

// Convert from degrees to steps
#define DEGREES_TO_STEPS(degrees) ((degrees) / DEGREES_PER_STEP)

void deploy_arm(void);
void run(void);

int main(void)
{
	AVR_init();
	
	// Turn on all motors
	int i;
	for (i=0; i<6; i++)
		motor_pwr(i, 1);

    while (1) 
    {
		// Run the test
		run();

		// Wait for five seconds and restart
		_delay_ms(5000);
    }
}

void run() {
	// Deploy base
	motor_dir(BASE_MOTOR, CLOCKWISE /* TODO: Verify correct direction */);
	motor_step(BASE_MOTOR, 400 /* TODO: Verify correct number of steps */, SPEED);

	// Rotate camera
	motor_dir(CAMERA_MOTOR, CLOCKWISE);
	motor_step(CAMERA_MOTOR, DEGREES_TO_STEPS(90), SPEED);

	motor_dir(CAMERA_MOTOR, COUNTERCLOCKWISE);
	motor_step(CAMERA_MOTOR, DEGREES_TO_STEPS(180), SPEED);

	motor_dir(CAMERA_MOTOR, CLOCKWISE);
	motor_step(CAMERA_MOTOR, DEGREES_TO_STEPS(90), SPEED);

	// Rotate arm
	motor_dir(ARM_ROTATION_MOTOR, CLOCKWISE);
	motor_step(ARM_ROTATION_MOTOR, DEGREES_TO_STEPS(90), SPEED);

	motor_dir(ARM_ROTATION_MOTOR, COUNTERCLOCKWISE);
	motor_step(ARM_ROTATION_MOTOR, DEGREES_TO_STEPS(180), SPEED);

	motor_dir(ARM_ROTATION_MOTOR, CLOCKWISE);
	motor_step(ARM_ROTATION_MOTOR, DEGREES_TO_STEPS(90), SPEED);

	// Raise arm 90 degrees and then back to a 45 degree angle
	motor_dir(SHOULDER_MOTOR, CLOCKWISE);
	motor_step(SHOULDER_MOTOR, DEGREES_TO_STEPS(90), SPEED);

	motor_dir(SHOULDER_MOTOR, COUNTERCLOCKWISE);
	motor_step(SHOULDER_MOTOR, DEGREES_TO_STEPS(45), SPEED);

	// Extend forearm
	motor_dir(ELBOW_MOTOR, COUNTERCLOCKWISE);
	motor_step(ELBOW_MOTOR, DEGREES_TO_STEPS(180), SPEED);

	// Wobble arm (tilt 45 degrees left and right)
	motor_dir(ARM_TILT_MOTOR, CLOCKWISE);
	motor_step(ARM_TILT_MOTOR, DEGREES_TO_STEPS(45), SPEED);

	motor_dir(ARM_TILT_MOTOR, COUNTERCLOCKWISE);
	motor_step(ARM_TILT_MOTOR, DEGREES_TO_STEPS(90), SPEED);

	motor_dir(ARM_TILT_MOTOR, CLOCKWISE);
	motor_step(ARM_TILT_MOTOR, DEGREES_TO_STEPS(45), SPEED);
	
	// Rotate arm
	motor_dir(ARM_ROTATION_MOTOR, CLOCKWISE);
	motor_step(ARM_ROTATION_MOTOR, DEGREES_TO_STEPS(180), SPEED);

	motor_dir(ARM_ROTATION_MOTOR, COUNTERCLOCKWISE);
	motor_step(ARM_ROTATION_MOTOR, DEGREES_TO_STEPS(360), SPEED);

	motor_dir(ARM_ROTATION_MOTOR, CLOCKWISE);
	motor_step(ARM_ROTATION_MOTOR, DEGREES_TO_STEPS(180), SPEED);

	// Retract forearm
	motor_dir(ELBOW_MOTOR, CLOCKWISE);
	motor_step(ELBOW_MOTOR, DEGREES_TO_STEPS(180), SPEED);

	// Retract arm
	motor_dir(SHOULDER_MOTOR, COUNTERCLOCKWISE);
	motor_step(SHOULDER_MOTOR, DEGREES_TO_STEPS(45), SPEED);

	// Retract base
	motor_dir(BASE_MOTOR, COUNTERCLOCKWISE /* TODO: Verify correct direction */);
	motor_step(BASE_MOTOR, 400 /* TODO: Verify correct number of steps */, SPEED);
}
