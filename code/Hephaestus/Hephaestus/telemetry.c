/*
 * telemetry.c
 *
 * Created: 1/18/2017 10:44:49 AM
 *  Author: Michael Humphrey
 */ 

#include "telemetry.h"
#include "RSXAVRD.h"
#include <avr/eeprom.h>
#include <string.h>

uint16_t current_address;

void telemetry_init(void) {
	current_address = eeprom_read_word(0);
	if (current_address == 0xFFFF) {
		current_address = 2;
	}
}

// Sends a code with the predefined TELEMETRY_TIME constant.
// Define in telemetry.h
/*
void inline telemetry_send_code(uint8_t code) {
	send_code(code, TELEMTRY_TIME);
}
*/

// Log a message to the EEPROM
void eeprom_log(char* message) {
	eeprom_update_block(message, (void *) (uint16_t) current_address, strlen(message)+1);
	current_address += strlen(message)+1;
	eeprom_update_word(0, current_address);
}
