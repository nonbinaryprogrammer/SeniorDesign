/* Designer: n/a
 * Filename: test.c
 * Date: n/a
 * Description: temporary test main.c
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "RSXAVRD.h"

volatile uint16_t seconds = 0;

//TIMER COUNTER 0 INT: executes on 1 second intervals
ISR(TIMER0_OVF_vect){
	seconds++;
}

//EXTERNAL INT 6: Timer Event 0 Interrupt Routine - Begin Experiment
ISR(INT6_vect){
	//fill in
}

//EXTERNAL INT 5: Timer Event 1 Interrupt Routine - Emergency Shutoff
ISR(INT5_vect){
	//fill in
}

int main() {
	AVR_init(); //Setup system
	//DDRB = 0xFF;
	timer_counter_enable(0x01,0x01); //Start 0.1 second timer
	camera_enable(0x01);
	//motor_pwr(0x05, 0x01);
	//motor_dir(0x05, 0x00);
	//PORTD = (1<<PD5);
	while(1) {
		send_code(0xFF, 0);
		send_code(0x00, 0);
	}
	//while(1){motor_step(0x05, 1600, 0x01, 93);}
	
	/*while (get_time() < 5920){}
	camera_enable(1);

	motor_pwr(0,1);
	_delay_ms(500);

	motor_pwr(1,1);
	_delay_ms(500);

	motor_pwr(2,1);
	_delay_ms(500);

	motor_pwr(3,1);
	_delay_ms(500);

	motor_pwr(4,1);
	_delay_ms(500);

	motor_pwr(5,1);
	_delay_ms(500);

	motor_dir(5, 0);
	motor_step(5, 1650, 28, 99);
	while (get_time() < 10040){}
	motor_dir(5, 1);
	motor_step(5, 1650, 28, 99);
	motor_pwr(0,0);
	motor_pwr(1,0);
	motor_pwr(2,0);
	motor_pwr(3,0);
	motor_pwr(4,0);
	motor_pwr(5,0);
	camera_enable(0x00);
	*/
	while(1){} //Don't let the main() run off, just idle instead
	return 0;
}
