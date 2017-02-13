/* Designer: Jonathan Hardman
 * Filename: RSXAVRD.h
 * Version: 1.1
 * Date: 01/31/17
 * Description: AVR ATmega64 I/O Drivers for RS-X Project
*/

/**********************General**********************/
//Sets up microcontroller I/O properties, run before everything.
void AVR_init(void);

//Enable or disable the time keeping of the AVR
void timer_counter_enable(uint8_t flag);

//Enable or Disable Timer Event Interrupt flags, event: 0 or 1, flag: 1=On, 0=Off
void timer_event_enable(uint8_t event, uint8_t flag);

//Checks for any successful touch on all touch point switches, reutrns 1 for connection, 0 for no connection
uint8_t touch_sensor_check(void);

//Sends lower 4bits provided for ms amount of milliseconds
void send_code(uint8_t code, uint8_t ms);

/*******************Motor Control*******************/
//Turn on/off for motor selected, motor: 0-4, flag: 1=On 0=Off 
void calibration_enable(uint8_t motor, uint8_t flag);

//Turns on/off motor selected, motor: 0-5, flag: 1=On 0=Off
void motor_pwr(uint8_t motor, uint8_t flag);

//Sets the motor turning direction, motor: 0-5, dir: 1=CCW 0=CW
void motor_dir(uint8_t motor, uint8_t dir);

//Steps the motor at a given speed, motor: 0-5, steps: <65535, speed: 0-100
void motor_step(uint8_t motor, uint16_t steps, uint16_t speed);



