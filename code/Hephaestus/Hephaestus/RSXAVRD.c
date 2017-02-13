/* Designer: Jonathan Hardman
 * Filename: RSXAVRD.c
 * Version: 1.1
 * Date: 01/31/17
 * Description: AVR ATmega64 I/O Drivers for RS-X Project
*/

/********Libraries********/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "RSXAVRD.h"

/*********Parallel Lines Config*********/
#define LINES_DDR &DDRD
#define LINES_PORT &PORTD
#define LINE0_PIN 4
#define LINE1_PIN 5
#define LINE2_PIN 6
#define LINE3_PIN 7

/*********Motor Driver Config*********/
#define MOTOR_EN_DDR &DDRF
#define MOTOR_EN_PORT &PORTF
#define MOT0_EN_PIN 2
#define MOT1_EN_PIN 3
#define MOT2_EN_PIN 4
#define MOT3_EN_PIN 5
#define MOT4_EN_PIN 6
#define MOT5_EN_PIN 7

#define MOTOR_STEP_DDR &DDRC
#define MOTOR_STEP_PORT &PORTC
#define MOT0_STEP_PIN 0
#define MOT1_STEP_PIN 1
#define MOT2_STEP_PIN 2
#define MOT3_STEP_PIN 3
#define MOT4_STEP_PIN 4
#define MOT5_STEP_PIN 5

#define MOTOR_DIR_DDR &DDRA
#define MOTOR_DIR_PORT &PORTA
#define MOT0_DIR_PIN 0
#define MOT1_DIR_PIN 1
#define MOT2_DIR_PIN 2
#define MOT3_DIR_PIN 3
#define MOT4_DIR_PIN 4
#define MOT5_DIR_PIN 5

#define MOT0_CALIB_INT 0
#define MOT1_CALIB_INT 1
#define MOT2_CALIB_INT 2
#define MOT3_CALIB_INT 3
#define MOT4_CALIB_INT 4
#define RSX_TE0_INT 5
#define RSX_TE1_INT 6

volatile uint8_t calibration = 0x00;
volatile uint8_t timer_event0_flg = 0x00;
volatile uint8_t timer_event1_flg = 0x00;

volatile uint16_t time = 0x00; //in tenths of a second

/*********Interrupts*********/
//Calibration Interrupt function for motor 0
ISR(INT0_vect){
	calibration |= 0x01;
}

//Calibration Interrupt function for motor 1
ISR(INT1_vect){
	calibration |= 0x02;
}

//Calibration Interrupt function for motor 2
ISR(INT2_vect){
	calibration |= 0x04;
}

//Calibration Interrupt function for motor 3
ISR(INT3_vect){
	calibration |= 0x08;
}

//Calibration Interrupt function for motor 4
ISR(INT4_vect){
	calibration |= 0x10;
}

//Timer Event 0 Interrupt Function - Begin Experiment
ISR(INT5_vect){
	timer_event0_flg = 0x01;
}

//Timer Event 1 Interrupt Function - Emergency Shutoff
ISR(INT6_vect){
	timer_event1_flg = 0x01;
	/* Or do something else here */
}

ISR(TIMER0_OVF_vect){
	PORTD ^= 0x01;
}

ISR(TIMER1_COMPA_vect){
	//PORTD ^= 0x01; //For timing testing
	time++;
}

/***********************************General***********************************/
void AVR_init(){
	*MOTOR_EN_DDR |= (1<<MOT0_EN_PIN | 1<<MOT1_EN_PIN | 1<<MOT2_EN_PIN | 1<<MOT3_EN_PIN | 1<<MOT4_EN_PIN | 1<<MOT5_EN_PIN);
	*MOTOR_DIR_DDR |= (1<<MOT0_DIR_PIN | 1<<MOT1_DIR_PIN | 1<<MOT2_DIR_PIN | 1<<MOT3_DIR_PIN | 1<<MOT4_DIR_PIN | 1<<MOT5_DIR_PIN);
	*MOTOR_STEP_DDR |= (1<<MOT0_STEP_PIN | 1<<MOT1_STEP_PIN | 1<<MOT2_STEP_PIN | 1<<MOT3_STEP_PIN | 1<<MOT4_STEP_PIN | 1<<MOT5_STEP_PIN);
	EICRA |= (1<<ISC31 | 1<<ISC30 | 1<<ISC21 | 1<<ISC20 | 1<<ISC11 | 1<<ISC10 | 1<<ISC01 | 1<<ISC00);
	EICRB |= (1<<ISC71 | 1<<ISC70 | 1<<ISC61 | 1<<ISC60 | 1<<ISC51 | 1<<ISC50 | 1<<ISC41 | 1<<ISC40);
	
	//8-bit Fast-PWM mode, no prescaling, 255 top, OCR3A comp (set on match) 
	TCCR1B |= (1<<WGM12 | 1<<CS11 | 1<<CS10); //64 prescale
	OCR1A = 0x30D4;
	DDRD |= 0x01;
}

void timer_counter_enable(uint8_t flag){
	cli();
	if(flag == 0x01)
		TIMSK |= (1<<OCIE1A);
	else
		TIMSK |= (1<<OCIE1A);
	sei();
}

void timer_event_enable(uint8_t event, uint8_t flag){
	cli();
	uint8_t eventID [2] = {RSX_TE0_INT, RSX_TE1_INT};
	if(flag == 0x01)
		EIMSK |= (1<<eventID[event]);
	else{
		EIMSK &= (1<<eventID[event]);
		timer_event0_flg = 0x00;
		timer_event1_flg = 0x00;
	}
	sei();
}

uint8_t touch_sensor_check(){
	if((PINE & 0x04) > 0x00)
		return 0x01;
	else
		return 0x00;
}

void send_code(uint8_t code, uint8_t ms){
	uint8_t i;
	*LINES_DDR |= (1<<LINE0_PIN | 1<<LINE1_PIN | 1<<LINE2_PIN | 1<<LINE3_PIN);
	*LINES_PORT |= ((code&0x01)<<LINE0_PIN | (code&0x02)<<LINE1_PIN | (code&0x04)<<LINE2_PIN | (code&0x08)<<LINE3_PIN);
	for(i=0;i<ms;i++)
		_delay_ms(1);
	*LINES_PORT &= ~(1<<LINE0_PIN | 1<<LINE1_PIN | 1<<LINE2_PIN | 1<<LINE3_PIN);
}

/***********************************Motor Driver Functions***********************************/
void motor_pwr(uint8_t motor, uint8_t flag){
	uint8_t motorENID[6] = {MOT0_EN_PIN, MOT1_EN_PIN, MOT2_EN_PIN,
					   MOT3_EN_PIN, MOT4_EN_PIN, MOT5_EN_PIN};
	if(flag == 0x01)
		*MOTOR_EN_PORT &= ~(1<<motorENID[motor]);
	else
		*MOTOR_EN_PORT |= (1<<motorENID[motor]);
}

void motor_dir(uint8_t motor, uint8_t dir){
	uint8_t motorDIRID[6] = {MOT0_DIR_PIN, MOT1_DIR_PIN, MOT2_DIR_PIN,
					   MOT3_DIR_PIN, MOT4_DIR_PIN, MOT5_DIR_PIN};
	if(dir == 0x01)
		*MOTOR_DIR_PORT |= (1<<motorDIRID[motor]);
	else
		*MOTOR_DIR_PORT &= ~(1<<motorDIRID[motor]);
}

void motor_step(uint8_t motor, uint16_t steps, uint16_t speed){
	uint16_t j,k;
	uint8_t motorSTEPID[6] = {MOT0_STEP_PIN, MOT1_STEP_PIN, MOT2_STEP_PIN, MOT3_STEP_PIN, MOT4_STEP_PIN, MOT5_STEP_PIN};
	speed = -99*(speed)+10000;
	steps = 2*steps;
	for (j=0;j<steps;j++){
		if(calibration == 0x00){
			*MOTOR_STEP_PORT ^= (1<<motorSTEPID[motor]);
			for (k=0;k<speed;k++)
				_delay_us(1);
		}else{
			*MOTOR_STEP_PORT &= (1<<motorSTEPID[motor]);
			break;
		}
	}
}

void calibration_enable(uint8_t motor, uint8_t flag){
	uint8_t motorCBID[6] = {MOT0_CALIB_INT, MOT1_CALIB_INT, MOT2_CALIB_INT, MOT3_CALIB_INT, MOT4_CALIB_INT};
	cli();
	if(flag == 0x01)
		EIMSK |= (1<<motorCBID[motor]);
	else
		EIMSK &= (1<<motorCBID[motor]);	
	sei();
}

