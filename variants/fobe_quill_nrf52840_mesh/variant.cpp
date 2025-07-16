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

    // Battery Sense
    pinMode(PIN_VBAT, INPUT);

    // Charging
    pinMode(PIN_CHARGING, INPUT);

    // MFP Power off
    pinMode(PIN_MFP_PWR, OUTPUT);
    digitalWrite(PIN_MFP_PWR, LOW);

    // TFT Disable
    pinMode(PIN_TFT_EN, OUTPUT);
    digitalWrite(PIN_TFT_EN, HIGH);

    // TFT Backlight Off
    pinMode(PIN_TFT_BLK, OUTPUT);
    digitalWrite(PIN_TFT_BLK, HIGH);
}
