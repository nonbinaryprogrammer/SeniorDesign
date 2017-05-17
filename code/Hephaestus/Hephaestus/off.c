#include "telemetry.h"

int off(void) {

	eeprom_log("power off");

	while(1){};

	// This return statement should never be reaches, so return error.
	return 1;
}