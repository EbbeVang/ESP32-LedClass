#include <Arduino.h>
#include <LedLight.h>

using namespace std;

    int pinNumber = 2;
    long lastMillils = 0;
    int pulseDelay = 200;
    bool pulse = false;
    int pwmResolution = 8;
    int pwmFreq = 5000;
    int ledChannel = 0;
    int pulseIncrease = 15;
    int dutyCycle = 0;
    int dutyCycleMin = 10;
    int dutyCycleMax = 200;
    LedLight::LedLight(int pin, int channel)
    {
        pinNumber = pin;
        pinMode(pinNumber, OUTPUT);

        ledChannel = channel;

        // configure LED PWM functionalitites
        ledcSetup(ledChannel, pwmFreq, pwmResolution);
        // attach the channel to the GPIO to be controlled
        ledcAttachPin(pinNumber, ledChannel);
    } 

    void LedLight::on()
    {
        //digitalWrite(pinNumber, HIGH); 
        pulse = false;  
        ledcWrite(ledChannel, 255);
    }

    void LedLight::off()
    {
        //digitalWrite(pinNumber, LOW);  
        pulse = false;
        ledcWrite(ledChannel, 0);
    }

    void setPulseDelay(int delay)
    {
        pulseDelay = delay;
    }

    void LedLight::setPulse(bool state)
    {
        pulse = state;
    }

    void LedLight::loop()
    { 
        if (pulse == true)
        {
                          

                if (millis() > lastMillils + pulseDelay)
                {
                    dutyCycle += pulseIncrease;
                    lastMillils = millis();
                    dutyCycle = constrain(dutyCycle, dutyCycleMin, dutyCycleMax);
                    Serial.println(dutyCycle);

                    ledcWrite(ledChannel, dutyCycle);
                }  
                if ((dutyCycle >= dutyCycleMax && pulseIncrease > 0) || (dutyCycle <= dutyCycleMin && pulseIncrease < 0) )
                {
                    pulseIncrease *= -1; //revert increase
                }
               
                     
        }
        else dutyCycle = 0;
    }

   