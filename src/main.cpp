#include <Arduino.h>
#include <LedLight.h>


LedLight led(2);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() 
{
  Serial.println("on");
  led.on();
  delay(1000);
  
  Serial.println("off");
  led.off();
  delay(1000);
}