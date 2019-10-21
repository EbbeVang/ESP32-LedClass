#include <Arduino.h>
#include <LedLight.h>

LedLight statusLED(2, 0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  statusLED.setPulse(true);
}

void loop() 
{
  // used for pulse
  statusLED.loop();
}