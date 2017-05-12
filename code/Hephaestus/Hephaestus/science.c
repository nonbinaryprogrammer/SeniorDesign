#include <avr/io.h>
#include "phases.h"
#include "RSXAVRD.h"
#include "telemetry.h"

/*
* Design of science phase: arm will move to touch sensor and press it. Upon moving the arm to the location, we will
* check whether the touch sensor was pressed and change our status to represent whether or not it was pressed.
* We will also write a code over the telemetry lines to represent whether or not the touch sensor was pressed.
*/

//Interrupt for touch sensor being depressed (oh no, so sad)
ISR(INT6_vect){
	if(touch_sensor_check() != 0x01){
		telemetry_send_code(TOUCH_SENSOR_1_ENGAGED);
	}
}

int science(){
	int status = 0;
	int M1_POS, M2_POS, M3_POS, M4_POS;
	int M1_NXT, M2_NXT, M3_NXT, M4_NXT;
	int M1_DIF, M2_DIF, M3_DIF, M4_DIF;
	int M1_DIF, M2_DIF, M3_DIF, M4_DIF;
	int scale factor = 0.225;

	// init motor values to 0
	M1_POS = 0;
	M2_POS = 0;
	M3_POS = 0;
	M4_POS = 0;

	// turn on camera
	camera_enable();

	// power on motors
	motor_pwr(1, 1);
	motor_pwr(2, 1);
	motor_pwr(3, 1);
	motor_pwr(4, 1);

	//set motor direction to be forward
	motor_dir(1, 0);
	motor_dir(2, 0);
	motor_dir(3, 0);
	motor_dir(4, 0);
	
	// TODO retrieve the next position
	
	//change _NXT values to be less than 360
	if(M1_NXT > 359) {
		M1_NXT = M1_NXT - 359;
	}

	if(M2_NXT > 359) {
		M2_NXT = M2_NXT - 359;
	}

	if(M3_NXT > 359) {
		M3_NXT = M3_NXT - 359;
	}

	if(M4_NXT > 359) {
		M4_NXT = M4_NXT - 359;
	}
	
	// calculate change in each motor (in degrees)
	M1_DIF = M1_NXT - M1_POS;
	M2_DIF = M2_NXT - M2_POS;
	M3_DIF = M3_NXT - M3_POS;
	M4_DIF = M4_NXT - M4_POS;

	// reverse motor direction for negative difference
	if(M1_DIF < 0) {
		motor_dir(1, 1);
		M1_DIF = M1_DIF * -1;
	}

	if(M2_DIF < 0) {
		motor_dir(2, 1);
		M2_DIF = M2_DIF * -1;
	}

	if(M3_DIF < 0) {
		motor_dir(3, 1);
		M3_DIF = M3_DIF * -1;
	}

	if(M4_DIF < 0) {
		motor_dir(4, 1);
		M4_DIF = M4_DIF * -1;
	}

	// convert degress to steps
	M1_STP = M1_DIF / scale_factor;
	M2_STP = M2_DIF / scale_factor;
	M3_STP = M3_DIF / scale_factor;
	M4_STP = M4_DIF / scale_factor;

	// move each motor that many steps
	motor_step(1, M1_STP, 28, 99);
	motor_step(2, M2_STP, 28, 99);
	motor_step(3, M3_STP, 28, 99);
	motor_step(4, M4_STP, 28, 99);

	// set the current position
	M1_POS = M1_NXT;
	M2_POS = M2_NXT;
	M3_POS = M3_NXT;
	M4_POS = M4_NXT;

	// code to return arm to callibrated "home" position
	if(get_calibration_status() != 0x01){ // or whichever motor refers to the home position
		status = 1;
	}

	return status;

}
