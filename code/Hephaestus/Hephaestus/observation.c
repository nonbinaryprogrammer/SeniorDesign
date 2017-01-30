
/*  observation.c
 *  Created: 1/22/2017 5:12:25 PM
 *  Author: Amber Horvath
 */

#include <avr/io.h>
#include "phases.h"

int observation(){

 // idea - GoPro's run an "autoexec.ash" file upon startup - preload our GoPro with a file that instantly turns it on and sets it to
 // record data until powered down?
 // note: this will void warranty
 // list of autoexec.ash's developed by some guy on github: https://github.com/KonradIT/autoexechack
 //
 // note: also running under the assumption that the camera will turn on automatically when a pin goes high - need to confirm with EE's that this is the case
 //
 //
 // if camera fails to turn on or fails to run autoexec.ash, then we need to report an error

}


