/* Designer: Jonathan Hardman
 * Filename: test.c
 * Date: 01/31/17
 * Description: tests RSXAVRD drivers
*/

#include <avr/io.h>
#include "telemetry.h"
#include "RSXAVRD.h"

int main() {
	telemetry_init();

	eeprom_log("Testing1");
	eeprom_log("Test2");
	eeprom_log("TestingTesting3");

	uint8_t i;
	for (i=0; i<=0x0F;i++) {
		send_code(i, 0xFF);
	}
	
	while(1){} //Don't let the main() run off, just idle instead
	return 0;
}