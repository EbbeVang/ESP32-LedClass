/*
Documentation:
https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/unit-tests.html
https://docs.platformio.org/en/latest/tutorials/core/unit_testing_blink.html#tutorial-unit-testing-blink
https://docs.platformio.org/page/plus/unit-testing.html
*/

#include <Arduino.h>
#include <unity.h>
#include <LedLight.h>

int pin = 2;
LedLight ledLight(pin);

void setUp(void) {
    //set stuff up here
}

// void tearDown(void) {
// // clean stuff up here
// }

void test_ledlight_off(void)
{
    ledLight.off();
    delay(500);
    TEST_ASSERT_EQUAL(digitalRead(pin), LOW);
}

void test_ledlight_on(void)
{
    ledLight.on();
    delay(500);
    TEST_ASSERT_EQUAL(digitalRead(pin), HIGH);
}

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();    // Start unittesting
    
    RUN_TEST(test_ledlight_on);



    RUN_TEST(test_ledlight_off);

    UNITY_END(); // Stop unittesting
    
}

void loop()
{
    
}