/*
 * off.c
 *
 * Created: 6/11/2017 8:44:04 PM
 *  Author: Michael Humphrey
 */ 

#include "telemetry.h"

int off (void) {

	eeprom_log("power off");
	telemetry_send_code(OFF_PHASE);

	// Loop infinitely doing nothing.
	while (1) {};

	// This return statement should never be reached, so return error.
	return 1;

}