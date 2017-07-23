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

uint8_t inline is_calibrated(void);

int science(void) {
	eeprom_log("Entered science mode");

	motor_pwr(MOTOR_DECK_ARM, 1);
	motor_pwr(MOTOR_PAN, 1);
	motor_pwr(MOTOR_SHOULD, 1);
	motor_pwr(MOTOR_ELB, 1);

	// Template
	//motor_dir(motor, dir);
	//motor_step(motor, steps, mult, SPEED);

	for (int i=0; i<2; i++) {
		// Fully extend arm (shoulder – 180, elbow – 180)
		motor_dir(MOTOR_SHOULD, CLOCKWISE);
		motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(180), 1, SPEED);
		_delay_ms(100); // Pause .1 seconds

		motor_dir(MOTOR_ELB, CLOCKWISE);
		motor_step(MOTOR_ELB, DEGREES_TO_STEPS(180), 1, SPEED);
		_delay_ms(2000); // Wait two seconds

		// Fold back to original position.
		motor_dir(MOTOR_ELB, COUNTER_CLOCKWISE);
		motor_step(MOTOR_ELB, DEGREES_TO_STEPS(180), 1, SPEED);
		_delay_ms(100);  // Pause .1 seconds

		motor_dir(MOTOR_SHOULD, COUNTER_CLOCKWISE);
		motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(180), 1, SPEED);
		_delay_ms(1000); // Wait one second


		if (is_calibrated()) {
			break; // If we've retracted to the home position, continue to the next movement
		}          // Otherwise, try again.
	}

	
	// Fully extend arm (shoulder – 180, elbow – 180)
	motor_dir(MOTOR_SHOULD, CLOCKWISE);
	motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(180), 1, SPEED);
	_delay_ms(100); // Pause .1 seconds

	motor_dir(MOTOR_ELB, CLOCKWISE);
	motor_step(MOTOR_ELB, DEGREES_TO_STEPS(180), 1, SPEED);
	_delay_ms(1000); // Wait one second

	
	// Wave arm
	for (int i=0; i<8; i++) {
		motor_dir(MOTOR_ELB, COUNTER_CLOCKWISE);
		motor_step(MOTOR_ELB, DEGREES_TO_STEPS(30), 1, SPEED);
		_delay_ms(100);

		motor_dir(MOTOR_ELB, CLOCKWISE);
		motor_step(MOTOR_ELB, DEGREES_TO_STEPS(30), 1, SPEED);
		_delay_ms(100);
	}

	// Contact touch sensor
	// Todo: touch sensor

	// Fold arm into home position (from fully extended)
	motor_dir(MOTOR_ELB, COUNTER_CLOCKWISE);
	motor_step(MOTOR_ELB, DEGREES_TO_STEPS(180), 1, SPEED);
	_delay_ms(100);  // Pause .1 seconds

	motor_dir(MOTOR_SHOULD, COUNTER_CLOCKWISE);
	motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(180), 1, SPEED);
	_delay_ms(1000); // Wait one second

	// Power off motors
	motor_pwr(MOTOR_DECK_ARM, POWER_OFF);
	motor_pwr(MOTOR_PAN,      POWER_OFF);
	motor_pwr(MOTOR_SHOULD,   POWER_OFF);
	motor_pwr(MOTOR_ELB,      POWER_OFF);

	telemetry_send_code(SCIENCE_PHASE);
	eeprom_log("Exiting science mode.");

	return 0; // Return success
}

uint8_t inline is_calibrated(void) {
	return get_calibration_status();
}
