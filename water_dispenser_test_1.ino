#include<Servo.h>

#define LED 10
#define PIR 11
#define SERVO 13

int pirState = 0;
Servo dispenser;

void setup(){
	pinMode(LED, OUTPUT);
  	pinMode(PIR, INPUT);
  	dispenser.attach(SERVO);
  
  	Serial.begin(9600);
}

void loop(){
	pirState = digitalRead(PIR);
  	if (pirState){
  		dispenser.write(90);
    	digitalWrite(LED, HIGH);
    	Serial.println("Water is flowing!");
      	delay(10000);
      	
  	}
  	dispenser.write(0);
  	digitalWrite(LED, LOW);
  	Serial.println("No movement!");
}
