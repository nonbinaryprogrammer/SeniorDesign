/*
 * Hephaestus.c
 *
 * Created: 1/17/2017 6:05:07 PM
 * Author : Michael Humphrey
 */ 

#include <avr/io.h>
#include "phases.h"


int main(void)
{
	// Pin configuration
	// TODO: Initialize pin configuration here

	int status = 0;

    /* Replace with your application code */
    while (1) 
    {
		// Phase 1: Idle
		status = idle();

		// Phase 2: Observation
		status = observation();

		// Phase 3: Science
		status = science();
		if (status != 0) {
			safety();
		}

		// Phase 4: Off
		status = off();

		// Phase 5: Safety
		status = safety();
    }
}

