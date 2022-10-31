#include<Servo.h>

int servoPin = 1;
int ledPin  = 11;
int pirPin = 0;

int state = 0; // state ensures that the servo doesn't activate consecutively
// state = 1 is true and state = 0 is false
int value; // angle value for servo's rotation
Servo dispenserServo; // declaring our servo motor's name

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  // Configuring servo motor's pin
  dispenserServo.attach(servoPin);
}

void loop()
{

  int pirState = digitalRead(pirPin); // reads PIR sensor's reading 1 is HIGH i.e. activated and 0 is LOW i.e. deactivated
  dispenserServo.write(value); // defines the value to 0 degrees
  
  if(pirState == 1 && state == 0) /* PIR is activated and Servo is deactivated */{
    value+=90; // change in angle for the servo
    digitalWrite(ledPin, HIGH); // LED indicating the activation
    dispenserServo.write(value); // Servo shifts to 90 degrees
    state = 1; // signifies that the servo is activated
    Serial.println("Sensor activated!"); // For confirmation in the serial monitor
    delay(1000); // 1 second's delay
  }
  else{
    value = 0; // change in angle for the servo to set it back at its original position
  	digitalWrite(ledPin, LOW); // LED indicating deactivation
    dispenserServo.write(value); // Servo shifts back to 0 degrees
    state = 0; // signifies that the servo is deactivated
    Serial.println("Sensor deactivated!"); // For confirmation in the serial monitor
  }
  
}
