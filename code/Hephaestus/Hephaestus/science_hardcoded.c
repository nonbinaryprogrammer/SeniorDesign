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

#define SPEED_FAST 90
#define SPEED_SLOW 90

int science(void) {
	eeprom_log("Entered science mode.");

	motor_pwr(MOTOR_DECK_ARM, 1);
	motor_pwr(MOTOR_PAN, 1);
	motor_pwr(MOTOR_SHOULD, 1);
	motor_pwr(MOTOR_ELB, 1);

	// Template
	//motor_dir(motor, dir);
	//motor_step(motor, steps, mult, SPEED);

	
	//motor_dir(MOTOR_SHOULD, COUNTER_CLOCKWISE);
	//motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(360), 2, SPEED_FAST);

	//motor_dir(MOTOR_SHOULD, CLOCKWISE);
	//motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(360), 2, SPEED_FAST);
	
	
	//motor_dir(MOTOR_ELB, CLOCKWISE);
	//motor_step(MOTOR_ELB, DEGREES_TO_STEPS(360), 1, SPEED_FAST);
	
	//motor_dir(MOTOR_PAN, CLOCKWISE);
	//motor_step(MOTOR_PAN, DEGREES_TO_STEPS(360), 1, SPEED_FAST);




	// Extend shoulder
	//motor_dir(MOTOR_SHOULD, CLOCKWISE);
	//motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(120), 1, SPEED_FAST);

	// Extend elbow
	//motor_dir(MOTOR_ELB, CLOCKWISE);
	//motor_step(MOTOR_ELB, DEGREES_TO_STEPS(180), 1, SPEED_FAST);

	_delay_ms(500);

	// Do a little spinny spin
	//motor_dir(MOTOR_PAN, CLOCKWISE);
	//motor_step(MOTOR_PAN, DEGREES_TO_STEPS(90), 1, SPEED_FAST);
	_delay_ms(100);

	//motor_dir(MOTOR_PAN, COUNTER_CLOCKWISE);
	//motor_step(MOTOR_PAN, DEGREES_TO_STEPS(180), 1, SPEED_FAST);
	_delay_ms(100);

	//motor_dir(MOTOR_PAN, CLOCKWISE);
	//motor_step(MOTOR_PAN, DEGREES_TO_STEPS(90), 1, SPEED_FAST);

	_delay_ms(500);

	// Do a little floppy flop
	//motor_dir(MOTOR_DECK_ARM, CLOCKWISE);
	//motor_step(MOTOR_DECK_ARM, DEGREES_TO_STEPS(45), 1, SPEED_SLOW);
	_delay_ms(100);

	//motor_dir(MOTOR_DECK_ARM, COUNTER_CLOCKWISE);
	//motor_step(MOTOR_DECK_ARM, DEGREES_TO_STEPS(90), 1, SPEED_SLOW);
	_delay_ms(100);

	//motor_dir(MOTOR_DECK_ARM, CLOCKWISE);
	//motor_step(MOTOR_DECK_ARM, DEGREES_TO_STEPS(45), 1, SPEED_SLOW);

	_delay_ms(1500);
	/*
	// Wave arm
	motor_dir(MOTOR_ELB, COUNTER_CLOCKWISE);
	motor_step(MOTOR_ELB, DEGREES_TO_STEPS(30), 1, SPEED_FAST);
	_delay_ms(100);

	motor_dir(MOTOR_ELB, CLOCKWISE);
	motor_step(MOTOR_ELB, DEGREES_TO_STEPS(30), 1, SPEED_FAST);
	_delay_ms(100);

	motor_dir(MOTOR_ELB, COUNTER_CLOCKWISE);
	motor_step(MOTOR_ELB, DEGREES_TO_STEPS(30), 1, SPEED_FAST);
	_delay_ms(100);

	motor_dir(MOTOR_ELB, CLOCKWISE);
	motor_step(MOTOR_ELB, DEGREES_TO_STEPS(30), 1, SPEED_FAST);

	_delay_ms(500);
	
	// Retract shoulder
	motor_dir(MOTOR_ELB, COUNTER_CLOCKWISE);
	motor_step(MOTOR_ELB, DEGREES_TO_STEPS(190), 1, SPEED_FAST);

	// Retract elbow
	motor_dir(MOTOR_SHOULD, COUNTER_CLOCKWISE);
	motor_step(MOTOR_SHOULD, DEGREES_TO_STEPS(120), 1, SPEED_FAST);
	*/

	eeprom_log("Exiting science mode.");

	return 0;
}