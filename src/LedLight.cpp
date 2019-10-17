#include <Arduino.h>
#include <LedLight.h>

using namespace std;

    int pinNumber = 2;
   
    LedLight::LedLight()
    {
        pinNumber = 2;
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

    void LedLight::pulse()
    {
        // make a cool pulse function
    }

   