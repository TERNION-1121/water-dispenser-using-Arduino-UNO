#include<Servo.h>

#define LED 10
#define TRIG 8
#define ECHO 9
#define SERVO 13
#define LOWER_RANGE 8
#define UPPER_RANGE 15

#define LED_S 11
#define TRIG_S 6
#define ECHO_S 7
#define SERVO_S 12
#define LOWER_RANGE_S 0
#define UPPER_RANGE_S 7

long duration = 0, duration_s = 0;
int distance = 0, distance_s = 0;
Servo dispenser;
Servo soap;

void setup(){
	pinMode(LED, OUTPUT);
  	pinMode(TRIG, OUTPUT);
  	pinMode(ECHO, INPUT);
  	dispenser.attach(SERVO);
  	dispenser.write(0);
  
  	pinMode(LED_S, OUTPUT);
  	pinMode(TRIG_S, OUTPUT);
  	pinMode(ECHO, INPUT);
	soap.attach(SERVO_S);
  	soap.write(0);
  
  	Serial.begin(9600);
}

void loop(){
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;
  if(distance >= LOWER_RANGE && distance <= UPPER_RANGE){
  		digitalWrite(LED, HIGH);
    	dispenser.write(90);
    	Serial.println("Activated!");
    	Serial.println(distance);
    	delay(500);
  }
  dispenser.write(0);
  digitalWrite(LED, LOW);
  
  digitalWrite(TRIG_S, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_S, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_S, LOW);
  duration_s = pulseIn(ECHO_S, HIGH);
  distance_s = duration_s * 0.034 / 2;
  if(distance_s > LOWER_RANGE_S && distance_s <= UPPER_RANGE_S){
  	digitalWrite(LED_S, HIGH);
    soap.write(90);
    Serial.println("Soap Activated!");
    Serial.println(distance_s);
    delay(500);
  }
    soap.write(0);
    digitalWrite(LED_S, LOW);
}
