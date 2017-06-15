/* Designer: Jonathan Hardman
 * Filename: test.c
 * Date: 01/31/17
 * Description: tests RSXAVRD drivers
*/

#include <avr/io.h>
#include <util/delay.h>
#include "telemetry.h"
#include "retract.h"
#include "RSXAVRD.h"
#include "MOTOR_DEF.h"

int main() {
	AVR_init();

	/*
	extend();
	_delay_ms(1500);
	retract();
	*/

	uint8_t motor = MOTOR_ELB;

	motor_pwr(motor, POWER_ON);
	motor_dir(motor, CLOCKWISE);
	motor_step(motor, DEGREES_TO_STEPS(360), 1, SPEED);

	_delay_ms(1000);
	
	motor_dir(motor, COUNTER_CLOCKWISE);
	motor_step(motor, DEGREES_TO_STEPS(360), 1, SPEED);
	motor_pwr(motor, POWER_OFF);

	
	while(1){} // Don't let the main() run off, just idle instead
	return 0;
}