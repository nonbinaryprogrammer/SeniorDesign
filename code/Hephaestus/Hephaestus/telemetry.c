/*
 * telemetry.c
 *
 * Created: 1/18/2017 10:44:49 AM
 *  Author: Michael Humphrey
 */ 

// Sends a code with the predefined TELEMETRY_TIME constant.
void inline send_code(uint8_t code) {
	send_code(code, TELEMTRY_TIME);
}


// Log a message to the SD card
void SD_log(char* message) {
	// Write elapsed time to SD card
	char *result = (char*) malloc(6*sizeof(char)); // Max value of get_time() is 65535, which is 5 characters, plus 1 for null terminator

	if (result == NULL)
		return;

	itoa(get_time(), result, 10);
	// Write result string to SD card
	free(result);

	// Write separator to SD card

	// Write message to SD card

	// Write line terminator to SD card
}
