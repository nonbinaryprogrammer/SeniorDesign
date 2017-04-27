#include <avr/io.h>
#include "phases.h"
#include "RSXAVRD.h"
#include "telemetry.h"

/*
* Design of science phase: arm will move to touch sensor and press it. Upon moving the arm to the location, we will
* check whether the touch sensor was pressed and change our status to represent whether or not it was pressed.
* We will also write a code over the telemetry lines to represent whether or not the touch sensor was pressed.
*/


int science(){

     int status = 0;

     camera_enable(); // turns on camera
     
	// code to move arm to designated location here

	if(touch_sensor_check() == 0x01){ // has the touch sensor been depressed? (oh no that sounds sad)
		send_code(/*code relating to which sensor was depressed - ask michael what code we use for sensors*/);
		
	}
	else{
		send_code(/*code saying sensor wasn't touched*/);
		
	}

	// code to return arm to callibrated "home" position

	if(get_calibration_status() != 0x01){ // or whichever motor refers to the home position
		status = 1;
	}

	return status;

}
