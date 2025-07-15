#include "variant.h"
#include "nrf.h"
#include "wiring_constants.h"
#include "wiring_digital.h"

const uint32_t g_ADigitalPinMap[] = {
    // P0
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,

    // P1
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47};

void initVariant()
{
    // LED
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    // Button
    pinMode(PIN_BUTTON1, INPUT);
    pinMode(PIN_ENCODER_A, INPUT);
    pinMode(PIN_ENCODER_B, INPUT);
    pinMode(PIN_ENCODER_BTN, INPUT);

    // Battery Sense
    pinMode(PIN_VBAT, INPUT);

    // Charging
    pinMode(PIN_CHARGING, INPUT);

    // Peripheral Power off
    pinMode(PIN_PERI_EN, OUTPUT);
    digitalWrite(PIN_PERI_EN, LOW);

    // GNSS Power off
    pinMode(PIN_GNSS_EN, OUTPUT);
    digitalWrite(PIN_GNSS_EN, LOW);
}
