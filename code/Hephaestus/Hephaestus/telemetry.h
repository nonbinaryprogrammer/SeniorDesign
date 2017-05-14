/*
 * telemetry.h
 *
 * Created: 1/18/2017 10:42:02 AM
 *  Author: Michael Humphrey
 */ 


#ifndef TELEMETRY_H_
#define TELEMETRY_H_

#include <stdint.h>

// Telemetry codes
#define IDLE ((uint8_t) 0x00)
#define CALIBRATION_SUCCESS ((uint8_t) 0x01)
#define TOUCH_SENSOR_1_ENGAGED ((uint8_t) 0x02)
#define TOUCH_SENSOR_2_ENGAGED ((uint8_t) 0x03)
#define OBSERVATION_PHASE ((uint8_t) 0x04)
#define SCIENCE_PHASE ((uint8_t) 0x05)
#define RETRACT_PHASE ((uint8_t) 0x06)
#define OFF_PHASE ((uint8_t) 0x07)
#define SAFETY_PHASE ((uint8_t) 0x08)
#define UNDEFINED9 ((uint8_t) 0x09)
#define UNDEFINEDA ((uint8_t) 0x0A)
#define UNDEFINEDB ((uint8_t) 0x0B)
#define UNDEFINEDC ((uint8_t) 0x0C)
#define UNDEFINEDD ((uint8_t) 0x0D)
#define UNDEFINEDE ((uint8_t) 0x0E)
#define MOTION_ERROR ((uint8_t) 0x0F)

// Time to send telemetry codes. Use this constant so it can be easily adjusted later
#define TELEMTRY_TIME ((uint8_t) 10)

// Define separator for SD card.
#define SEPARATOR '\t'

// Define line terminator for SD card.
#define LINE_TERMINATOR '\n'

// Sends a code with the predefined TELEMETRY_TIME constant.
void inline telemetry_send_code(uint8_t code);

// Log a message to the EEPROM
void eeprom_log(char* message);

// Log a message to the SD card - DEPRECATED
//void SD_log(char* message);

#endif /* TELEMETRY_H_ */