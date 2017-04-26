/*
 * Hephaestus.c
 *
 * Created: 1/17/2017 6:05:07 PM
 * Author : Michael Humphrey
 */ 

#include <avr/io.h>
#include "phases.h"
#include "RSXAVRD.h"


int main(void)
{
	// Pin configuration
	AVR_init();

	int status = 0;

	//timer_counter_enable(1,1); // code that enables timer event - Jon says Michael wanted this?

	timer_event_enable(0,1); // enables timer event line 0

	timer_event_enable(1,1); // enables timer event line 1

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
