#include <Arduino.h>
#include <LedLight.h>


LedLight firstObject;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() 
{
  firstObject.on();
  delay(1000);
  firstObject.off();
  delay(1000);
}