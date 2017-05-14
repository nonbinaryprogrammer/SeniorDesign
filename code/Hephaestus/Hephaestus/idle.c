/*
 * idle.c
 *
 * Created: 1/20/2017 3:36:32 PM
 *  Author: Michael Humphrey
 */

#include "RSXAVRD.h"
#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t ready = 0;

ISR(INT6_vect) {
	ready = 1;
}

 // First phase of payload deployment. Wait for TE-R lines to go high, then return.
 int idle(void) {
	
	// Infinite loop until receive signal to start
	while (!ready) {}

	return 0;
}
