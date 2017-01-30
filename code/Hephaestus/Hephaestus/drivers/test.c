/* Designer: Jonathan Hardman
 * Filename: test.c
 * Date: 01/20/17
 * Description: tests RSXAVRD drivers
*/

#include <avr/io.h>
#include "RSXAVRD.h"

int main() {
	init_motors();
	motor_pwr(0x00,0x00);
	motor_dir(0x00,0x01);
	while(1){
		step_motor(0,1600,97); //6400 steps per rotation, 1600 = 1/4 rotation (90 degrees)
	}
	while(1){}
	return 0;
}