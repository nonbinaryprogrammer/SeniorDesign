/*
 * science_hardcoded.c
 *
 * Created: 6/15/2017 12:03:28 PM
 *  Author: Michael Humphrey
 */ 

#include <avr/io.h>
#include "retract.h"
#include "RSXAVRD.h"
#include "telemetry.h"
#include "MOTOR_DEF.h"
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t done = 0;

uint8_t inline is_calibrated(void);

// Out of time interrupt
ISR(INT5_vect){
	done = 1;
}

int science(void) {
	eeprom_log("Entered science mode");

	// Turn on motors
	motor_pwr(MOTOR_CAMERA, POWER_ON);
	motor_pwr(MOTOR_DECK_ARM, 1);
	motor_pwr(MOTOR_PAN, 1);
	motor_pwr(MOTOR_SHOULD, 1);
	motor_pwr(MOTOR_ELB, 1);

	/*
	// Enable interrupts on motors
	motor_calibration_enable(MOTOR_DECK_ARM, 1);
	motor_calibration_enable(MOTOR_PAN, 1);
	motor_calibration_enable(MOTOR_SHOULD, 1);
	motor_calibration_enable(MOTOR_ELB, 1);
	*/

	// Template
	//motor_dir(motor, dir);
	//motor_step(motor, steps, mult, SPEED);

	// Try this two times
	for (int i=0; i<2; i++) {
		// Fully extend arm (shoulder – 180, elbow – 180)
		motor_dir(MOTOR_SHOULD, CLOCKWISE);
		motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(180), 1, SPEED);
		_delay_ms(100); // Pause .1 seconds

		motor_dir(MOTOR_ELB, CLOCKWISE);
		motor_step(MOTOR_ELB, DEGREES_TO_STEPS(180), 1, SPEED);
		_delay_ms(1000); // Wait one seconds

		// Fold back to original position.
		motor_dir(MOTOR_ELB, COUNTER_CLOCKWISE);
		motor_step(MOTOR_ELB, DEGREES_TO_STEPS(180), 1, SPEED);
		_delay_ms(100);  // Pause .1 seconds

		motor_dir(MOTOR_SHOULD, COUNTER_CLOCKWISE);
		motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(180), 1, SPEED);
		_delay_ms(1000); // Wait one second


		if (is_calibrated()) {
			eeprom_log("Arm calibrated");
			telemetry_send_code(CALIBRATION_SUCCESS);
			break; // If we've retracted to the home position, continue to the next movement
		} else {   // Otherwise, try again.
			eeprom_log("Arm not calibrated");
		}
	}

	
	// Fully extend arm (shoulder – 180, elbow – 180)
	motor_dir(MOTOR_SHOULD, CLOCKWISE);
	motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(180), 1, SPEED);
	_delay_ms(100); // Pause .1 seconds

	motor_dir(MOTOR_ELB, CLOCKWISE);
	motor_step(MOTOR_ELB, DEGREES_TO_STEPS(180), 1, SPEED);
	_delay_ms(1000); // Wait one second

	
	eeprom_log("Waving arm");
	// Wave arm
	while (!done) {
		motor_dir(MOTOR_ELB, COUNTER_CLOCKWISE);
		motor_step(MOTOR_ELB, DEGREES_TO_STEPS(30), 1, SPEED-10);
		_delay_ms(200);

		motor_dir(MOTOR_ELB, CLOCKWISE);
		motor_step(MOTOR_ELB, DEGREES_TO_STEPS(30), 1, SPEED-10);
		_delay_ms(200);
	}
	eeprom_log("Folding up");

	// Fold arm into home position (from fully extended)
	motor_dir(MOTOR_ELB, COUNTER_CLOCKWISE);
	motor_step(MOTOR_ELB, DEGREES_TO_STEPS(180), 1, SPEED);
	_delay_ms(100);  // Pause .1 seconds

	motor_dir(MOTOR_SHOULD, COUNTER_CLOCKWISE);
	motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(180), 1, SPEED);
	_delay_ms(1000); // Wait one second

	// One more camera sweep
	motor_pwr(MOTOR_CAMERA, POWER_ON); // power on the motor for the camera
	motor_dir(MOTOR_CAMERA, CLOCKWISE); // set the camera to move clockwise
	motor_step(MOTOR_CAMERA, DEGREES_TO_STEPS(225), 1, 70);
	_delay_ms(500);

	motor_dir(MOTOR_CAMERA, COUNTER_CLOCKWISE);
	motor_step(MOTOR_CAMERA, DEGREES_TO_STEPS(360), 1, 70);
	_delay_ms(500);

	motor_dir(MOTOR_CAMERA, CLOCKWISE);
	motor_step(MOTOR_CAMERA, DEGREES_TO_STEPS(180), 1, 70);
	_delay_ms(500);


	telemetry_send_code(SCIENCE_PHASE);
	eeprom_log("Exiting science mode.");

	return 0; //is_calibrated(); // Return success
}

uint8_t inline is_calibrated(void) {
	return get_calibration_status() & 1;
}
