#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "RSXAVRD.h"
#include "phases.h"
#include "retract.h"

uint8_t plate_retracted_flg; // flag to keep track of plate's position

ISR(INT5_vect){
	
	if(plate_retracted_flg == 0x00){
		retract();
	}

}

void retract(){ // decide whether to make this as a void or not

	motor_pwr(5, 1); // 5 is the motor number for the base
	
	_delay_ms(500); // allow motor to just Chill for a bit after turning on

	motor_pwr(4, 0); // turn off all other motors
	motor_pwr(3, 0);
	motor_pwr(2, 0);
	motor_pwr(1, 0);

	camera_enable(); // turns off camera - might not need this line? since the experimental power off 
	
	motor_dir(5, 1); // pull the deck plate in

	motor_step(5, 1650, 28, 99); // the amount of steps needed to pull the arm back in

	plate_retracted_flg = 0x01;


}

void extend(){

	motor_pwr(5, 1); // powers on deck plate motor

	_delay_ms(500); // delays to allow motor to power on

	motor_dir(5, 0); // push the deck plate out

	motor_step(5, 1650, 28, 99); // the amount of steps needed to move the deck plate at a good speed

	plate_retracted_flg = 0x00; // plate is NOT retracted


}
