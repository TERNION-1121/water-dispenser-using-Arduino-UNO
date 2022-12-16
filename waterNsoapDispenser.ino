#include<Servo.h>

int servoWaterPin = 13;
int ledWaterPin  = 10;
int pirWaterPin = 11;

int servoSoapPin = 7;
int ledSoapPin = 5;
int pirSoapPin = 9;

Servo WaterDispenserServo; // declaring our servo motor's name
Servo SoapDispenserServo;

void setup()
{
  Serial.begin(9600);
  pinMode(ledWaterPin, OUTPUT);
  pinMode(ledSoapPin, OUTPUT);
  
  // Configuring servo motor's pin
  WaterDispenserServo.attach(servoWaterPin);
  SoapDispenserServo.attach(servoSoapPin);
}

void loop()
{
  waterDispenser(digitalRead(pirWaterPin));
  soapDispenser(digitalRead(pirSoapPin));
}

void waterDispenser(int pirState)
{
  int waterState = 0;
  int valueW = 0;
  WaterDispenserServo.write(valueW); // defines the value to 0 degrees
  
  if(pirState == 1 && waterState == 0) /* PIR is activated and Servo is deactivated */{
    valueW+=90; // change in angle for the servo
    digitalWrite(ledWaterPin, HIGH); // LED indicating the activation
    WaterDispenserServo.write(valueW); // Servo shifts to 90 degrees
    waterState = 1; // signifies that the servo is activated
    Serial.println("Sensor activated!"); // For confirmation in the serial monitor
    delay(1000); // 1 second's delay
  }
  else{
    valueW = 0; // change in angle for the servo to set it back at its original position
  	digitalWrite(ledWaterPin, LOW); // LED indicating deactivation
    WaterDispenserServo.write(valueW); // Servo shifts back to 0 degrees
    waterState = 0; // signifies that the servo is deactivated
    Serial.println("Sensor deactivated!"); // For confirmation in the serial monitor

  }
}

void soapDispenser(int pirState)
{
  int soapState = 0;
  int valueS = 0;
  SoapDispenserServo.write(valueS); // defines the value to 0 degrees
  
  if(pirState == 1 && soapState == 0) /* PIR is activated and Servo is deactivated */{
    valueS+=90; // change in angle for the servo
    digitalWrite(ledSoapPin, HIGH); // LED indicating the activation
    SoapDispenserServo.write(valueS); // Servo shifts to 90 degrees
    soapState = 1; // signifies that the servo is activated
    Serial.println("Sensor activated!"); // For confirmation in the serial monitor
    delay(1000); // 1 second's delay
  }
  else{
    valueS = 0; // change in angle for the servo to set it back at its original position
  	digitalWrite(ledSoapPin, LOW); // LED indicating deactivation
    SoapDispenserServo.write(valueS); // Servo shifts back to 0 degrees
    soapState = 0; // signifies that the servo is deactivated
    Serial.println("Sensor deactivated!"); // For confirmation in the serial monitor

  }
}