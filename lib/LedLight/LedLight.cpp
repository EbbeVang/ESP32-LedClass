#include <Arduino.h>
#include <LedLight.h>

using namespace std;

    int pinNumber = 2;
   
    LedLight::LedLight(int pin)
    {
        pinNumber = pin;
        pinMode(pinNumber, OUTPUT);
    } 

    void LedLight::on()
    {
        digitalWrite(pinNumber, HIGH);
    }

    void LedLight::off()
    {
        digitalWrite(pinNumber, LOW);
    }

   