/* Designer: Jonathan Hardman
 * Filename: test.c
 * Date: 01/31/17
 * Description: tests RSXAVRD drivers
*/

#include <avr/io.h>
#include "RSXAVRD.h"

//Declared in RSXAVR.c: if the interrupt is enabled, will change to 0x01 when timer event is triggered.
extern uint8_t timer_event0_flg; //recieves values from driver
extern uint8_t timer_event1_flg;

int main() {
	AVR_init(); //Setup system
	timer_counter_enable(0x01);
	
	timer_event_enable(0x00,0x01); //Turn on the Timer Event 0 Interrupt
	while(timer_event0_flg == 0x00){} //idle until signal to start
	timer_event_enable(0x00,0x00); //Once done waiting, turn off interrupt to reset state
	
	//time to do stuff
	motor_calibration_enable(0x00,0x01); //Turn on calibration interrupt for motor 0
	motor_pwr(0x00,0x01); //Turn on power for motor 0
	motor_dir(0x00,0x01); //Set motor 0 rotation direction to CW
	timer_event_enable(0x01,0x01); //Turn on the Timer Event 1 Interrupt
	
	/*
	Might want to change Timer Event 1 Interrupt vector in RSXAVRD.c to execute 
	specific instructions for emergency retraction instead of waiting for flag.
	*/
	
	while(1) //continuously rotate till Timer Event 1 Interrupt
		motor_step(0,1600,97); //6400 steps per rotation, 1600 = 1/4 rotation (90 degrees)
	
	while(1){} //Don't let the main() run off, just idle instead
	return 0;
}