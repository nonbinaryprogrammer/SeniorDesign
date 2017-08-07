/*
 * idle.c
 *
 * Created: 1/20/2017 3:36:32 PM
 *  Author: Michael Humphrey
 */

#include "RSXAVRD.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "telemetry.h"

// If doesn't work, use volatile
volatile uint8_t ready = 0;

ISR(INT6_vect) {
	ready = 1;
}

 // First phase of payload deployment. Wait for TE-R lines to go high, then return.
 int idle(void) {
	
	// Infinite loop until receive signal to start
	
	eeprom_log("Checking inhibit");
	// Inhibit
	while (bit_is_set(PINE, 4)) {
		ready = 0;
	}

	eeprom_log("Entered idle phase");

	DDRE |= (1<<4);

	while (!ready) {}

	eeprom_log("idle phase complete");

	return 0;
}
