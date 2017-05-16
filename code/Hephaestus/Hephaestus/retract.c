#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "RSXAVRD.h"
#include "phases.h"
#include "retract.h"
#include "MOTOR_DEF.h"
#include "telemetry.h"

uint8_t plate_retracted_flg; // flag to keep track of plate's position

ISR(INT5_vect){
	
	if(plate_retracted_flg == 0x00){
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

	eeprom_log("deck plate has been retracted");

	plate_retracted_flg = 0x01;


}

void extend(){

	motor_pwr(MOTOR_DECK_PLATE, POWER_ON); // powers on deck plate motor

	_delay_ms(500); // delays to allow motor to power on

	motor_dir(MOTOR_DECK_PLATE, CLOCKWISE); // push the deck plate out

	motor_step(MOTOR_DECK_PLATE, 1650, 28, SPEED + 19); // the amount of steps needed to move the deck plate at a good speed

	plate_retracted_flg = 0x00; // plate is NOT retracted


}
