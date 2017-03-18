#include <stdio.h>

//=========DEFINITIONS==================
int encA_pin1 = 6;
int encB_pin1 = 7;
long encA_ticks1 = 0;
//for polling implementation
int n = LOW;
int encA_pin1_prev = LOW;

unsigned long time;
char buffer [50];
int i = 0;

int encA_pin2 = 2;
int encB_pin2 = 4;
volatile long encA_ticks2 = 0;

int encA_pin3 = 3;
int encB_pin3 = 5;
volatile long encA_ticks3 = 0;

const float pi = 3.14;

volatile int state = HIGH;

volatile float encA_degree1 = 0;
volatile float encA_degree2 = 0;
volatile float encA_degree3 = 0;

/*
2 - Motor 1: A
3 - Motor 1: B
4 - Motor 2: A
5 - Motor 2: B
6 - Motor 3: A
7 - Motor 3: B


*/
//=========SET-UP==================
void setup() {
  // put your setup code here, to run once:
pinMode(encA_pin1, INPUT);
pinMode(encA_pin2, INPUT);
pinMode(encA_pin3, INPUT);

digitalWrite(encA_pin1, HIGH);
digitalWrite(encA_pin2, HIGH);
digitalWrite(encA_pin3, HIGH);

pinMode(13, OUTPUT);

// INIT interrups

//switch motor 1 to polling
//attachInterrupt(digitalPinToInterrupt(encA_pin1),encoderA1,RISING);
attachInterrupt(digitalPinToInterrupt(encA_pin2),encoderA2,RISING);
attachInterrupt(digitalPinToInterrupt(encA_pin3),encoderA3,RISING);

Serial.begin(9600);
}


//========= LOOP ==================
void loop() {
  // put your main code here, to run repeatedly:

  time = millis();

  //Poll innermost motor to circumvent limited number
  //of Arduino UNO interupts
  n = digitalRead(encA_pin1);
   if ((encA_pin1_prev == LOW) && (n == HIGH)) {
     if (digitalRead(encB_pin1) == LOW) {
       encA_ticks1 -= 1.0;
     } else {
       encA_ticks1 += 1.0;
     }
   } 
   encA_pin1_prev = n;

  digitalWrite(13,state);

  //if enough time has passed, print a status update
  //print status update every .5 seconds

  //output the valid configurations to Serial which will then be stored in a file
  encA_degree1 = encA_ticks1*2.25;
  encA_degree2 = encA_ticks2*2.25;
  encA_degree3 = encA_ticks3*2.25;

  Serial.println("0");
  Serial.println(encA_degree1);
  Serial.println(encA_degree2);
  Serial.println(encA_degree3);
  Serial.println(";");

  delay(500);
}

//Arduino UNO only has two interupts
//Switch innermost motor to polling

//void encoderA1(){
//  state=!state;
//  if(digitalRead(encB_pin1)==HIGH){
//    encA_ticks1=encA_ticks1+1.0;
//  }else{
//    encA_ticks1=encA_ticks1-1.0;
//  }
//  }

void encoderA2(){
  state=!state;
  if(digitalRead(encB_pin2)==HIGH){
    encA_ticks2=encA_ticks2+1.0;
  }else{
    encA_ticks2=encA_ticks2-1.0;
  }
}
  
void encoderA3(){
  state=!state;
  if(digitalRead(encB_pin3)==HIGH){
    encA_ticks3=encA_ticks3+1.0;
  }else{
    encA_ticks3=encA_ticks3-1.0;
  }
  }
