#include<MQ2.h>
/* import this library from github */ 
int gasPin = A0;

int redPin = 11;
int orangePin = 10;
int yellowPin = 9;

MQ2 mq2(gasPin); 
void setup()
{
  Serial.begin(9600);
  pinMode(redPin, OUTPUT)
  mq2.begin();
}

void loop()
{
  float* values = mq2.read(false);
   /*
   * read the values from the sensor, it returns
   * an array which contains 3 values.
   * 0 : LPG in ppm
   * 1 : CO in ppm
   * 2 : SMOKE in ppm
   */
  
  /* 1. We have to know the natural ppm level of LPG, CO, and Smoke
     2. We have to set if statements:
     	if <current_ppm> > <natural_or_toxic_range>:
        	set the corresponding led pin to high */
  
}
