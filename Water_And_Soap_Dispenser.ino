#include<Servo.h>

enum PINS_WATER{LED_WATER = 10, TRIG_WATER = 8, ECHO_WATER = 9, SERVO_WATER = 13, LOWER_RANGE = 0, UPPER_RANGE = 10};
enum PINS_SOAP{LED_S = 11, TRIG_S = 6, ECHO_S = 7, SERVO_S1 = 12, SERVO_S2 = 5};


long duration = 0, duration_s = 0;
int distance = 0, distance_s = 0;

Servo dispenser;
Servo soap1;
Servo soap2;

void setup(){
	pinMode(LED_WATER, OUTPUT);
  	pinMode(LED_S, OUTPUT);
  
  	pinMode(TRIG_WATER, OUTPUT);
  	pinMode(TRIG_S, OUTPUT);
  	
  	pinMode(ECHO_WATER, INPUT);
  	pinMode(ECHO_S, INPUT);
  
  	dispenser.attach(SERVO_WATER);
  	soap1.attach(SERVO_S1);
 	soap2.attach(SERVO_S2);
  
  	dispenser.write(0);
  	soap1.write(0);
  	soap2.write(0);
  
  	Serial.begin(9600);
}

void loop(){
  
  digitalWrite(TRIG_WATER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_WATER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_WATER, LOW);
  duration = pulseIn(ECHO_WATER, HIGH);
  distance = duration * 0.034 / 2;
  if(distance >= LOWER_RANGE && distance <= UPPER_RANGE)
  {
  		digitalWrite(LED_WATER, HIGH);
    	dispenser.write(90);
    	Serial.println("Dispensing Water at range: ");
    	Serial.println(distance);
    	delay(1000);
  }
  
  digitalWrite(TRIG_S, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_S, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_S, LOW);
  duration_s = pulseIn(ECHO_S, HIGH);
  distance_s = duration_s * 0.034 / 2;
  if(distance_s > LOWER_RANGE && distance_s <= UPPER_RANGE)
  {
  		digitalWrite(LED_S, HIGH);
    	soap1.write(90);
    	soap2.write(90);
    	Serial.println("Dispensing Soap at Range: ");
    	Serial.println(distance_s);
    	delay(1000);
  }
  
    soap1.write(0);
  	soap2.write(0);
    digitalWrite(LED_S, LOW);
  
  	delay(500);
  
  	dispenser.write(0);
  	digitalWrite(LED_WATER, LOW);
}
