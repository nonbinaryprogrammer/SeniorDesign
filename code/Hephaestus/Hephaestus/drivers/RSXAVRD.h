/* Designer: Jonathan Hardman
 * Filename: RSXAVRD.h
 * Version: 1.0
 * Date: 01/20/17
 * Description: AVR ATmega64 I/O Drivers for RS-X Project
*/

/*******************Motor Control*******************/
//Run this before doing anything with motors or else...
void init_motors(void);

//Turns on/off motor selected, motor: 0-5, flag: 1=On 0=Off
void motor_pwr(uint8_t motor, uint8_t flag);

//Sets the motor turning direction, motor: 0-5, dir: 1=CCW 0=CW
void motor_dir(uint8_t motor, uint8_t dir);

//Steps the motor at a given speed, motor: 0-5, steps: <65535, speed: 0-100
void step_motor(uint8_t motor, uint16_t steps, uint16_t speed);

/******************Parallel Lines******************/
//Sends lower 4bits provided for ms amount of milliseconds
void send_code(uint8_t code, uint8_t ms);

