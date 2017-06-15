#include <avr/io.h>
#include "phases.h"
#include "RSXAVRD.h"
#include "telemetry.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

/*
* Design of science phase: arm will move to touch sensor and press it. Upon moving the arm to the location, we will
* check whether the touch sensor was pressed and change our status to represent whether or not it was pressed.
* We will also write a code over the telemetry lines to represent whether or not the touch sensor was pressed.
*/

int science(){
	uint8_t status = 0;
	uint8_t M1_POS, M2_POS, M3_POS, M4_POS;
	uint8_t M1_NXT, M2_NXT, M3_NXT, M4_NXT;
	uint8_t M1_DIF, M2_DIF, M3_DIF, M4_DIF;
	uint8_t M1_STP, M2_STP, M3_STP, M4_STP;
	float scale_factor = 0.225;
	char path_step;

	//TODO reference CSpace in program memory (the address of a 4D array in program memory)
	char**** cspace;
		
	// init motor values to 0
	M1_POS = 0;
	M2_POS = 0;
	M3_POS = 0;
	M4_POS = 0;

	// turn on camera
	camera_enable(1);

	// power on motors
	motor_pwr(1, 1);
	motor_pwr(2, 1);
	motor_pwr(3, 1);
	motor_pwr(4, 1);

	//repeat for length of path
	while(1) {
		//set motor direction to be forward
		motor_dir(1, 0);
		motor_dir(2, 0);
		motor_dir(3, 0);
		motor_dir(4, 0);
		
		//find the next point in the path
		path_step = cspace[M1_POS][M2_POS][M3_POS][M4_POS];

		uint8_t w, y, x, z, sx, sw, sy, sz, ew, ex, ey, ez;

		//set the lower and upper bounds for the loops so only indices 
		//in range are checked
		if(M1_POS == 0) { sw = 0; } else { sw = -1; }
		if(M2_POS == 0) { sx = 0; } else { sx = -1; }
		if(M3_POS == 0) { sy = 0; } else { sy = -1; }
		if(M4_POS == 0) { sz = 0; } else { sz = -1; }

		if(M1_POS == 36) { ew = 1; } else { ew = 2; }
		if(M2_POS == 36) { ex = 1; } else { ex = 2; }
		if(M3_POS == 36) { ey = 1; } else { ey = 2; }
		if(M4_POS == 36) { ez = 1; } else { ez = 2; }


		//check each of the neighboring points
		for(w=sw; w<ew; w++) {
			for(x=sx; x<ex; x++) {
				for(y=sy; y<ey; y++) {
					for(z=sz; z<ez; z++) {
						if(cspace[M1_POS+w][M2_POS+x][M3_POS+y][M4_POS+z] == path_step + 1) {
							M1_NXT = M1_POS + w;
							M2_NXT = M2_POS + x;
							M3_NXT = M3_POS + y;
							M4_NXT = M4_POS + z;
							break;
						}
					}
				}
			}
		}

		if(M1_NXT == M1_POS && M2_NXT == M2_POS && M3_NXT == M3_POS && M4_NXT == M4_POS) {
			//end of path has been reached
			//TODO send eop telemetry signal
			return 0;
		}

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

		// convert degrees to steps
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

		if(touch_sensor_check() == 0x01){
			telemetry_send_code(TOUCH_SENSOR_1_ENGAGED); // For now, always send TOUCH_SENSOR_1_ENGAGED.
		}

		// code to return arm to calibrated "home" position
		if(get_calibration_status() != 0x01){ // or whichever motor refers to the home position
			status = 1;
		}
		asdfasdjfal;skdjf
	}

	return status;

}
