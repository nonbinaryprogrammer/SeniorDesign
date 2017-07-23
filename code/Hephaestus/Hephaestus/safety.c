/* safety.c
 * 
 * Created by: Amber Horvath
 * Date Created: 1/22/17 5:36:47
 *
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include "phases.h"
#include "retract.h"
#include "telemetry.h"
#include "RSXAVRD.h"
#include "MOTOR_DEF.h"

int safety(void){
    
	eeprom_log("Houston, we have a problem"); // Jokes ftw

	eeprom_log("Cycling camera");
	// Save footage from camera by power cycling
	camera_enable(POWER_OFF);
	_delay_ms(2000); // Wait 2 seconds for camera to fully power off.
	camera_enable(POWER_ON);
	_delay_ms(2000); // Wait 2 seconds for camera to fully power on.

	eeprom_log("Retracting  arm");
    retract();

	eeprom_log("Abort mission");
	telemetry_send_code(SAFETY_PHASE);
    while(1){}; // abort mission, we are hanging here

}
