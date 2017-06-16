/*
 * Hephaestus.c
 *
 * Created: 1/17/2017 6:05:07 PM
 * Author : Michael Humphrey
 */ 

#include <avr/io.h>
#include "phases.h"
#include "RSXAVRD.h"
#include "retract.h"
#include "telemetry.h"


int main(void)
{
	// Pin configuration
	AVR_init();

	uint8_t status = 0;

	//timer_counter_enable(1,1); // code that enables timer event - Jon says Michael wanted this?

	timer_event_enable(0,1); // enables timer event line 0

	timer_event_enable(1,1); // enables timer event line 1

	eeprom_log("Program start.");

    /* Replace with your application code */
    while (1) 
    {
		// Phase 1: Idle
		status = idle();

		//retract();

		// Phase 2: Observation
		status = observation();

		// Phase 3: Science
		status = science();
		
		if (status != 0) { // if our arm is not calibrated i.e. collapsed and in home position...
			safety(); // turn off all motors and retract into a safe position
		} else {		   // otherwise, just retract the arm and end the experiment
			retract();
		}

		// Phase 4: Off
		status = off();
		// Under normal circumstances, off never returns.
		// Off only returns if there was an error.

		// Phase 5: Safety
		status = safety();
    }
}
