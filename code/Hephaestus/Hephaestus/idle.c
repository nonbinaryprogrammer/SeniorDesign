/*
 * idle.c
 *
 * Created: 1/20/2017 3:36:32 PM
 *  Author: Michael Humphrey
 */

#include "RSXAVRD.h"

// Grab variable from RSXAVRD.h
extern uint8_t timer_event0_flg;

 // First phase of payload deployment. Wait for TE-R lines to go high, then return.
 int idle(void) {
	
	// Infinite loop until start experiment flag is set to 1
	while (timer_event0_flg == 0) {}

	return 0;
}
