/*
 * demo.c
 *
 * Created: 5/18/2017 3:07:48 PM
 *  Author: Michael Humphrey
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "phases.h"
#include "RSXAVRD.h"
#include "MOTOR_DEF.h"


int main(void)
{
	// Pin configuration
	AVR_init();

	camera_enable(POWER_ON);				// Turn on camera
	motor_pwr(MOTOR_DECK_PLATE, POWER_ON);	// Power on deck plate motor
	motor_pwr(MOTOR_CAMERA, POWER_ON);		// Power on the motor for the camera

	_delay_ms(1000);

    while (1) 
    {
	    motor_dir(MOTOR_CAMERA, CLOCKWISE);

	    motor_step(MOTOR_CAMERA, DEGREES_TO_STEPS(360), 28, 95);

		_delay_ms(500); // Don't give the poor camera whiplash.
		
		motor_dir(MOTOR_CAMERA, COUNTER_CLOCKWISE);

		motor_step(MOTOR_CAMERA, DEGREES_TO_STEPS(360), 28, 95);

		extend();

		_delay_ms(2500);

		retract();
	}
}

void retract(){

	motor_pwr(MOTOR_DECK_PLATE, POWER_ON);
	
	_delay_ms(500); // delay for motor after powering on

	motor_pwr(MOTOR_CAMERA, POWER_OFF); // turn off all other motors
	motor_pwr(MOTOR_DECK_ARM, POWER_OFF);
	motor_pwr(MOTOR_PAN, POWER_OFF);
	motor_pwr(MOTOR_SHOULD, POWER_OFF);
	motor_pwr(MOTOR_ELB, POWER_OFF);

	camera_enable(POWER_OFF);
	
	motor_dir(MOTOR_DECK_PLATE, COUNTER_CLOCKWISE); // rotates the deck plate to

	motor_step(MOTOR_DECK_PLATE, 1650, 28, SPEED + 19); // the amount of steps needed to pull the arm back in
}

void extend(){
	motor_dir(MOTOR_DECK_PLATE, CLOCKWISE); // push the deck plate out

	motor_step(MOTOR_DECK_PLATE, 1650, 28, SPEED + 19); // the amount of steps needed to move the deck plate at a good speed
}
