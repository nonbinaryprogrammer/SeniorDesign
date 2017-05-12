/* safety.c
 * 
 * Created by: Amber Horvath
 * Date Created: 1/22/17 5:36:47
 *
 *
 */

#include <avr/io.h>
#include "phases.h"
#include "retract.h"

int safety(void){
    

    retract();

    while(1){}; // abort mission, we are hanging here

}
