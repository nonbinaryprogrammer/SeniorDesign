/*
 * off.c
 *
 * Created: 6/11/2017 8:44:04 PM
 *  Author: Michael Humphrey
 */ 

#include "telemetry.h"
#include "RSXAVRD.h"
#include "MOTOR_DEF.h"

int off (void) {
	motor_pwr(MOTOR_CAMERA, POWER_OFF);
	motor_pwr(MOTOR_DECK_ARM, POWER_OFF);
	motor_pwr(MOTOR_PAN, POWER_OFF);
	motor_pwr(MOTOR_SHOULD, POWER_OFF);
	motor_pwr(MOTOR_ELB, POWER_OFF);
	//motor_pwr(MOTOR_DECK_PLATE, POWER_OFF);
	camera_enable(POWER_OFF); // turns on camera


	eeprom_log("power off");
	telemetry_send_code(OFF_PHASE);

	// Loop infinitely doing nothing.
	while (1) {};

	// This return statement should never be reached, so return error.
	return 1;

}