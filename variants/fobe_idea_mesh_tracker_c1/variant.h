/*
  Copyright (c) 2025 FoBE Studio. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _FOBE_QUILL_NRF52840_MESH_H_
#define _FOBE_QUILL_NRF52840_MESH_H_

/** Master clock frequency */
#define VARIANT_MCK       (64000000ul)
#define USE_LFXO      // Board uses 32khz crystal for LF
//#define USE_LFRC    // Board uses RC for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Use the native nrf52 usb power detection
#define NRF_APM

// Pin definitions
#define PINS_COUNT (48)
#define NUM_DIGITAL_PINS (48)
#define NUM_ANALOG_INPUTS (7) // A5 is used for battery
#define NUM_ANALOG_OUTPUTS (0)

/*
 * LEDs
 */
#define PIN_LED1 (32 + 11)
#define LED_RED PIN_LED1
#define LED_BLUE PIN_LED1
#define LED_GREEN PIN_LED1
#define LED_BUILTIN PIN_LED1
#define LED_STATE_ON 0

/*
 * Buttons
 */
#define PIN_BUTTON1 (32 + 0)

/*
 * Analog pins
 */
#define PIN_A0               (0 + 3)
#define PIN_A1               (0 + 28)
#define PIN_A2               (0 + 2)
#define PIN_A3               (0 + 29)
#define PIN_A4               (0 + 31)
#define PIN_A5               (0 + 30)
#define PIN_A6               (0 + 5)
#define PIN_A7               (0xff) // to compile with Firmata library
static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
static const uint8_t A3  = PIN_A3 ;
static const uint8_t A4  = PIN_A4 ;
static const uint8_t A5  = PIN_A5 ;
static const uint8_t A6  = PIN_A6 ;
static const uint8_t A7  = PIN_A7 ;

/*
 * Battery
 */
#define ADC_RESOLUTION     (12)
#define PIN_VBAT           (0 + 5)
#define PIN_CHARGING       (32 + 12)

/*
 * NFC
 */
#define PIN_NFC1                (0 + 9)
#define PIN_NFC2                (0 + 10)

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA (0 + 7)
#define PIN_WIRE_SCL (0 + 27)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * Serial interfaces
 */
#define PIN_SERIAL1_RX (0 + 12)
#define PIN_SERIAL1_TX (32 + 9)

/*
 * SPI interfaces
 */
#define SPI_INTERFACES_COUNT    (1)
#define PIN_SPI_MISO            (0 + 24)
#define PIN_SPI_MOSI            (0 + 22)
#define PIN_SPI_SCK             (0 + 20)
static const uint8_t SS   = (32 + 8);
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * LoRa
 */
#define PIN_SX126X_NSS (32 + 8)
#define PIN_SX126X_DIO1 (0 + 17)
#define PIN_SX126X_BUSY (0 + 15)
#define PIN_SX126X_RESET (0 + 13)
#define PIN_SX126X_TXEN (-1)
#define PIN_SX126X_RXEN (0 + 11)
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8

/*
 * GNSS
 */
#define PIN_GNSS_PPS (0 + 8)
#define PIN_GNSS_RST (0 + 4)
#define PIN_GNSS_WAKE (0 + 6)
#define PIN_GNSS_TXD PIN_SERIAL1_TX
#define PIN_GNSS_RXD PIN_SERIAL1_RX
#define PIN_GNSS_EN (0 + 26)

/*
 * Screen
 */
#define PIN_OLED_SDA PIN_WIRE_SDA
#define PIN_OLED_SCL PIN_WIRE_SCL

/*
 * Buzzer
 */
#define PIN_BUZZER (0 + 14)

/*
 * Encoder
 */
#define PIN_ENCODER_A (32 + 6)
#define PIN_ENCODER_B (32 + 2)
#define PIN_ENCODER_BTN (32 + 4)

/*
 * Motion
 */
#define PIN_MOTION_PWR (32 + 15)
#define PIN_MOTION_INT (32 + 14)
#define PIN_MOTION_SDA (32 + 13)
#define PIN_MOTION_SCL (32 + 10)

/*
 * MFP
 */
#define PIN_MFP1 (0 + 25)
#define PIN_MFP2 (0 + 23)
#define PIN_MFP3 (0 + 21)
#define PIN_MFP4 (0 + 19)

/*
 * Power
 */
#define PIN_PERI_EN (0 + 16)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif
