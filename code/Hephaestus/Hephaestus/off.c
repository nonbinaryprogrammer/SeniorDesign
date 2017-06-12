/*
 * off.c
 *
 * Created: 6/11/2017 8:44:04 PM
 *  Author: mhump
 */ 

#include "telemetry.h"

int off (void) {

	eeprom_log("power off");

	// Loop infinitely doing nothing.
	while (1) {};

	// This return statement should never be reaches, so return error.
	return 1;

}