
/*  observation.c
 *  Created: 1/22/2017 5:12:25 PM
 *  Author: Amber Horvath
 */

#include <avr/io.h>
#include "phases.h"
#include "RSXAVRD.h"
#include "telemetry.h"
#include "MOTOR_DEF.h"

int observation(){

     
      camera_enable(POWER_ON); // turns on camera

      motor_pwr(MOTOR_CAMERA, POWER_ON); // power on the motor for the camera

      motor_dir(MOTOR_CAMERA, CLOCKWISE); // set the camera to move clockwise

      motor_step(MOTOR_CAMERA, DEGREES_TO_STEPS(180), 1, 85);

      _delay_ms(500);

      motor_dir(MOTOR_CAMERA, COUNTER_CLOCKWISE);

      motor_step(MOTOR_CAMERA, DEGREES_TO_STEPS(360), 1, 85);

      _delay_ms(500);

      motor_dir(MOTOR_CAMERA, CLOCKWISE);

      motor_step(MOTOR_CAMERA, DEGREES_TO_STEPS(180), 1, 85);

      _delay_ms(500); 

      telemetry_send_code(OBSERVATION_PHASE); // let us know we finished Observation mode

      eeprom_log("observation phase complete");

      return 0;


}


