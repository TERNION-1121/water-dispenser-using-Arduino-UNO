#include<Servo.h>

enum PINS_MASK{LED_MASK = 10, TRIG_MASK = 8, ECHO_MASK = 9, SERVO_MASK = 13, LOWER_RANGE = 0, UPPER_RANGE = 10};
enum PINS_SANITIZER{LED_S = 11, TRIG_S = 6, ECHO_S = 7, SERVO_S1 = 12, SERVO_S2 = 5};


long duration = 0, duration_s = 0;
int distance = 0, distance_s = 0;

Servo dispenser;
Servo soap1;
Servo soap2;

void setup(){
	pinMode(LED_MASK, OUTPUT);
  	pinMode(LED_S, OUTPUT);
  
  	pinMode(TRIG_MASK, OUTPUT);
  	pinMode(TRIG_S, OUTPUT);
  	
  	pinMode(ECHO_MASK, INPUT);
  	pinMode(ECHO_S, INPUT);
  
  	dispenser.attach(SERVO_MASK);
  	soap1.attach(SERVO_S1);
 	soap2.attach(SERVO_S2);
  
  	dispenser.write(0);
  	soap1.write(0);
  	soap2.write(0);
  
  	Serial.begin(9600);
}

void loop(){
  
  digitalWrite(TRIG_MASK, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_MASK, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_MASK, LOW);
  duration = pulseIn(ECHO_MASK, HIGH);
  distance = duration * 0.034 / 2;
  if(distance >= LOWER_RANGE && distance <= UPPER_RANGE)
  {
  		digitalWrite(LED_MASK, HIGH);
    	dispenser.write(90);
    	Serial.println("Dispensing Mask at Range: ");
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
    	Serial.println("Dispensing Sanitizer at Range: ");
    	Serial.println(distance_s);
    	delay(1000);
  }
  
    soap1.write(0);
  	soap2.write(0);
    digitalWrite(LED_S, LOW);
  
  	delay(500);
  
  	dispenser.write(0);
  	digitalWrite(LED_MASK, LOW);
}
