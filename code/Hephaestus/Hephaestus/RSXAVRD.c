/* Designer: Jonathan Hardman
 * Filename: RSXAVRD.c
 * Version: 3.1
 * Date: 04/25/17
 * Description: AVR ATmega64 I/O Drivers for RS-X Project
*/

/********Libraries********/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "RSXAVRD.h"

/********I/O Config********/
//Parallel Lines Output
#define LINES_DDR &DDRD
#define LINES_PORT &PORTD
#define LINE0_PIN 4
#define LINE1_PIN 5
#define LINE2_PIN 6
#define LINE3_PIN 7

//Parallel Lines Strobe Input
#define LINE_STROBE_DDR &DDRB
#define LINE_STROBE_PORT &PINB
#define LINE_STROBE_PIN 6

//Touch Points Input
#define TOUCH_PORT &PINB
#define TOUCH_PIN 4

//Motor Enable Output
#define MOTOR_EN_DDR &DDRF
#define MOTOR_EN_PORT &PORTF
#define MOT0_EN_PIN 2
#define MOT1_EN_PIN 3
#define MOT2_EN_PIN 4
#define MOT3_EN_PIN 5
#define MOT4_EN_PIN 6
#define MOT5_EN_PIN 7

//Motor Step Output
#define MOTOR_STEP_DDR &DDRC
#define MOTOR_STEP_PORT &PORTC
#define MOT0_STEP_PIN 0
#define MOT1_STEP_PIN 1
#define MOT2_STEP_PIN 2
#define MOT3_STEP_PIN 3
#define MOT4_STEP_PIN 4
#define MOT5_STEP_PIN 5

//Motor Direction Output
#define MOTOR_DIR_DDR &DDRA
#define MOTOR_DIR_PORT &PORTA
#define MOT0_DIR_PIN 5
#define MOT1_DIR_PIN 4
#define MOT2_DIR_PIN 3
#define MOT3_DIR_PIN 2
#define MOT4_DIR_PIN 1
#define MOT5_DIR_PIN 0

//Camera Enable Output
#define CAMERA_EN_DDR &DDRB
#define CAMERA_EN_PORT &PORTB
#define CAMERA_EN_PIN 5

//External Interrupt Map
#define MOT0_CALIB_INT 0
#define MOT1_CALIB_INT 1
#define MOT2_CALIB_INT 2
#define MOT3_CALIB_INT 3
#define MOT4_CALIB_INT 4
#define RSX_TE1_INT 5
#define RSX_TE0_INT 6

/*********Variables*********/
uint8_t calibration_flg = 0x00; //Will hold number other than 0 when calibration switch triggered
uint16_t time = 0x0000; //Holds time count in tenths of a second from when timer_counter_enable() is turned on

uint16_t get_time(){return time;}
uint8_t get_calibration_status(){return calibration_flg;}

/*********Interrupt Vectors*********/
//EXTERNAL INT 0: Calibration Interrupt function for motor 0
ISR(INT0_vect){
	calibration_flg |= 0x01;
}

//EXTERNAL INT 1: Calibration Interrupt function for motor 1
ISR(INT1_vect){
	calibration_flg |= 0x02;
}

//EXTERNAL INT 2: Calibration Interrupt function for motor 2
ISR(INT2_vect){
	calibration_flg |= 0x04;
}

//EXTERNAL INT 3: Calibration Interrupt function for motor 3
ISR(INT3_vect){
	calibration_flg |= 0x08;
}

//EXTERNAL INT 4: Inhibit
ISR(INT4_vect){
	//while(1) {};
}

//TIMER COUNTER 1 INT: Time Keeping Interrupt - increments time variable every 0.1 sec
ISR(TIMER1_COMPA_vect){
	time++;
}

/***********************************General***********************************/
void AVR_init(){
	//Motor Data Direction Setup
	*MOTOR_EN_DDR |= (1<<MOT0_EN_PIN | 1<<MOT1_EN_PIN | 1<<MOT2_EN_PIN | 1<<MOT3_EN_PIN | 1<<MOT4_EN_PIN | 1<<MOT5_EN_PIN);
	*MOTOR_DIR_DDR |= (1<<MOT0_DIR_PIN | 1<<MOT1_DIR_PIN | 1<<MOT2_DIR_PIN | 1<<MOT3_DIR_PIN | 1<<MOT4_DIR_PIN | 1<<MOT5_DIR_PIN);
	*MOTOR_STEP_DDR |= (1<<MOT0_STEP_PIN | 1<<MOT1_STEP_PIN | 1<<MOT2_STEP_PIN | 1<<MOT3_STEP_PIN | 1<<MOT4_STEP_PIN | 1<<MOT5_STEP_PIN);
	
	//Parallel Lines Data Direction Setup
	*LINES_DDR |= (1<<LINE0_PIN | 1<<LINE1_PIN | 1<<LINE2_PIN | 1<<LINE3_PIN);
	
	//Camera Data Direction Setup
	*CAMERA_EN_DDR |= (1<<CAMERA_EN_PIN);
	
	//External Interrupt Settings
	//Set all interrupts to trigger on rising edge
	EICRA |= (1<<ISC31 | 1<<ISC30 | 1<<ISC21 | 1<<ISC20 | 1<<ISC11 | 1<<ISC10 | 1<<ISC01 | 1<<ISC00);
	EICRB |= (1<<ISC61 | 1<<ISC60 | 1<<ISC51 | 1<<ISC50 | 1<<ISC41 | 1<<ISC40);
	
	//TimerCounter1: 16-bit CTC mode, 64 prescale, 12500 top, no output latching
	TCCR1B |= (1<<WGM12 | 1<<CS11 | 1<<CS10);
	OCR1A = 0x61AB; //25003 out of 65535

	//TimerCounter0: 8-bit normal mode, using 32.768 kHz clock, 64 prescale, no output latching
	ASSR |= (1<<AS0);
	TCCR0 |= (1<<CS02 | 1<< CS00);
	
	//Enable ADC, single conversion mode, use external common GND, right-adjusted.
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADEN);
}

void timer_counter_enable(uint8_t counter, uint8_t flag){
	cli();
	if(flag == 0x01){
		if(counter == 0)
			TIMSK |=(1<<TOIE0);
		if(counter == 1)
			TIMSK |= (1<<OCIE1A);
	}else{
		if(counter == 0)
			TIMSK &= ~(1<<TOIE0);
		if(counter == 1)
			TIMSK &= ~(1<<OCIE1A);

		time = 0x0000;
	}
	sei();
}

void timer_event_enable(uint8_t event, uint8_t flag){
	cli();
	uint8_t eventID[2] = {RSX_TE0_INT, RSX_TE1_INT};
	if(flag == 0x01)
		EIMSK |= (1<<eventID[event]);
	else
		EIMSK &= (1<<eventID[event]);
	sei();
}

void send_code(uint8_t code, uint8_t ms){
	uint8_t i;
	code = ((code & 0x0F)<<4);
	while(bit_is_clear(*LINE_STROBE_PORT,LINE_STROBE_PIN)){} //wait for PRS
	_delay_us(7); //wait for end of READ phase
	PORTD |= code;
	for(i=0;i<ms;i++)
		_delay_ms(1);
	while(bit_is_clear(*LINE_STROBE_PORT,LINE_STROBE_PIN)){} //wait for PRS
	_delay_us(7); //wait for end of READ phase
	PORTD &= ~(code);
}

/**************************************Device Functions**************************************/
void camera_enable(uint8_t flag){
	static uint8_t power = 0x00;
	if (((flag == 0x01)&(power == 0x00))||((flag == 0x00)&(power == 0x01))){
		*CAMERA_EN_PORT |= (1<<CAMERA_EN_PIN);
		_delay_ms(100);
		*CAMERA_EN_PORT &= ~(1<<CAMERA_EN_PIN);
		power = (power + 1) % 2;
	}
}

uint8_t touch_sensor_check(){
	if((*TOUCH_PORT & (1<<TOUCH_PIN)) > 0x00)
		return 0x01;
	else
		return 0x00;
}

uint16_t temperature_probe_sample(uint8_t probe){
	if(probe == 0x00)
		ADMUX &= ~(1<<MUX0);
	else
		ADMUX |= (1<<MUX0);
	ADCSRA |= (1<<ADSC); //Starts conversion
	while(ADCSRA & (1<<ADSC));
	return ADC;
}

/***********************************Motor Driver Functions***********************************/
void motor_calibration_enable(uint8_t motor, uint8_t flag){
	uint8_t motorCBID[] = {MOT0_CALIB_INT, MOT1_CALIB_INT, MOT2_CALIB_INT, MOT3_CALIB_INT, MOT4_CALIB_INT};
	cli();
	if(flag == 0x01)
		EIMSK |= (1<<motorCBID[motor]);
	else
		EIMSK &= (1<<motorCBID[motor]);
	calibration_flg = 0x00;
	sei();
}

void motor_pwr(uint8_t motor, uint8_t flag){
	uint8_t motorENID[6] = {MOT0_EN_PIN, MOT1_EN_PIN, MOT2_EN_PIN,
					   MOT3_EN_PIN, MOT4_EN_PIN, MOT5_EN_PIN};
	if(flag == 0x01)
		*MOTOR_EN_PORT |= (1<<motorENID[motor]);
	else
		*MOTOR_EN_PORT &= ~(1<<motorENID[motor]);
}

void motor_dir(uint8_t motor, uint8_t dir){
	uint8_t motorDIRID[6] = {MOT0_DIR_PIN, MOT1_DIR_PIN, MOT2_DIR_PIN,
					   MOT3_DIR_PIN, MOT4_DIR_PIN, MOT5_DIR_PIN};
	if(dir == 0x01)
		*MOTOR_DIR_PORT |= (1<<motorDIRID[motor]);
	else
		*MOTOR_DIR_PORT &= ~(1<<motorDIRID[motor]);
}

void motor_step(uint8_t motor, uint16_t steps, uint8_t mult, uint16_t speed){
	uint16_t j,k;
	uint8_t motorSTEPID[6] = {MOT0_STEP_PIN, MOT1_STEP_PIN, MOT2_STEP_PIN, MOT3_STEP_PIN, MOT4_STEP_PIN, MOT5_STEP_PIN};
	speed = -99*(speed)+10000;
	steps = steps*mult;
	for (j=0;j<steps;j++){
		if(calibration_flg == 0x00){
			*MOTOR_STEP_PORT ^= (1<<motorSTEPID[motor]);
			for (k=0;k<speed;k++)
				_delay_us(1);
		}else{
			*MOTOR_STEP_PORT &= (1<<motorSTEPID[motor]);
			break;
		}
	}
}
