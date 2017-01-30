/* Designer: Jonathan Hardman
 * Filename: RSXAVRD.c
 * Version: 1.0
 * Date: 01/20/17
 * Description: AVR ATmega64 I/O Drivers for RS-X Project
*/

/********Libraries********/
#include <avr/io.h>
//#include <avr/interrupt.h>
#include <util/delay.h>

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

/***********************************Motor Driver Functions***********************************/
void init_motors(){
	*MOTOR_EN_DDR |= (1<<MOT0_EN_PIN | 1<<MOT1_EN_PIN | 1<<MOT2_EN_PIN | 1<<MOT3_EN_PIN | 1<<MOT4_EN_PIN | 1<<MOT5_EN_PIN);
	*MOTOR_DIR_DDR |= (1<<MOT0_DIR_PIN | 1<<MOT1_DIR_PIN | 1<<MOT2_DIR_PIN | 1<<MOT3_DIR_PIN | 1<<MOT4_DIR_PIN | 1<<MOT5_DIR_PIN);
	*MOTOR_STEP_DDR |= (1<<MOT0_STEP_PIN | 1<<MOT1_STEP_PIN | 1<<MOT2_STEP_PIN | 1<<MOT3_STEP_PIN | 1<<MOT4_STEP_PIN | 1<<MOT5_STEP_PIN);
}

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

void step_motor(uint8_t motor, uint16_t steps, uint16_t speed){
	uint16_t i,j,k;
	uint8_t motorSTEPID[6] = {MOT0_STEP_PIN, MOT1_STEP_PIN, MOT2_STEP_PIN, MOT3_STEP_PIN, MOT4_STEP_PIN, MOT5_STEP_PIN};
	speed = -99*(speed)+10000;
	for(i=0;i<2;i++){
		for (j=0;j<steps;j++){
			*MOTOR_STEP_PORT ^= (1<<motorSTEPID[motor]);
			for (k=0;k<speed;k++)
				_delay_us(1);
		}
	}
}

/*********Parallel Lines Config*********/
#define LINES_DDR &DDRD
#define LINES_PORT &PORTD
#define LINE0_PIN 4
#define LINE1_PIN 5
#define LINE2_PIN 6
#define LINE3_PIN 7

/***********************************Parallel Lines Functions***********************************/
void send_code(uint8_t code, uint8_t ms){
	uint8_t i;
	*LINES_DDR |= (1<<LINE0_PIN | 1<<LINE1_PIN | 1<<LINE2_PIN | 1<<LINE3_PIN);
	*LINES_PORT |= ((code&0x01)<<LINE0_PIN | (code&0x02)<<LINE1_PIN | (code&0x04)<<LINE2_PIN | (code&0x08)<<LINE3_PIN);
	for(i=0;i<ms;i++)
		_delay_ms(1);
	*LINES_PORT &= ~(1<<LINE0_PIN | 1<<LINE1_PIN | 1<<LINE2_PIN | 1<<LINE3_PIN);
}

