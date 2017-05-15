/* Designer: Jonathan Hardman
 * Filename: RSXAVRD.h
 * Version: 3.1
 * Date: 04/25/17
 * Description: AVR ATmega64 I/O Drivers for RS-X Project
*/
/******************Variables/Flags******************/

#include <stdint.h>

//Returns time count in 0.1 seconds,
//Can be 0-65535 in 0.1s precision
uint16_t get_time(void);

//Returns Calibration Status, 
//0 for no calibration, 1=MOT0, 2=MOT1, 4=MOT2, 8=MOT3, 16=MOT4 calibrated
uint8_t get_calibration_status(void);

/**********************General**********************/
//Sets up microcontroller I/O properties, run before everything.
void AVR_init(void);

//Enable or disable the time keeping of the AVR
//counter: 0=1sec timer, 1=0.1sec timer,  flag: 1=On, 0=Off, time reset on turn-off
void timer_counter_enable(uint8_t counter, uint8_t flag);

//Enable or Disable Timer Event Interrupt flags, 
//event: 0 or 1, flag: 1=On, 0=Off
void timer_event_enable(uint8_t event, uint8_t flag);

//Sends lower 4bits provided for ms amount of milliseconds
void send_code(uint8_t code, uint8_t ms);

/**********************Devices**********************/
//Turn on/off the external camera,
//flag: 0=Off, 1=On
void camera_enable(uint8_t flag);

//Checks for any successful touch on all touch point switches, 
//returns 1 for connection, 0 for no connection
uint8_t touch_sensor_check(void);

//Samples and returns probe temperature in 10bit format, 
//probe: 0=Internal, 1=External, returns 16bit val with lower 10bits from ADC
uint16_t temperature_probe_sample(uint8_t probe);

/*******************Motor Control*******************/
//Turn on/off for motor selected, 
//motor: 0-4, flag: 1=On 0=Off 
void motor_calibration_enable(uint8_t motor, uint8_t flag);

//Turns on/off motor selected, 
//motor: 0-5, flag: 1=On 0=Off
void motor_pwr(uint8_t motor, uint8_t flag);

//Sets the motor turning direction, 
//motor: 0-5, dir: 1=CCW 0=CW
void motor_dir(uint8_t motor, uint8_t dir);

//Steps the motor at a given speed, mult variable is step count multiplier 
//NOTE: motors are 1600steps/rotation
//motor: 0-5, steps: <65535, mult: 0-255, speed: 0-100
void motor_step(uint8_t motor, uint16_t steps, uint8_t mult, uint16_t speed);

