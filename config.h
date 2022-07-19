// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

// Matrix configuration
// #define SPI_MATRIX_CHIP_SELECT_PIN C4
// #define SPI_MATRIX_DIVISOR 32

/*
 * SPI Configuration
 */
// #define SPI_DRIVER SPID1
// #define SPI_SCK_PIN A5
// #define SPI_SCK_PAL_MODE 5
// #define SPI_MOSI_PIN A6
// #define SPI_MOSI_PAL_MODE 5
// #define SPI_MISO_PIN A7
// #define SPI_MISO_PAL_MODE 5

/* ----- External EEPROM ----- */

#define SPI_DRIVER SPID1
#define SPI_SCK_PIN C10
#define SPI_MOSI_PIN C11
#define SPI_MISO_PIN C12
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN C3
#define EXTERNAL_FLASH_SPI_CLOCK_DIVISOR 8             // ? going with the default
#define EXTERNAL_FLASH_PAGE_SIZE 256                   // from spec
#define EXTERNAL_FLASH_SECTOR_SIZE (4 * 1024)          // EXTERNAL_FLASH_SIZE / 4096
#define EXTERNAL_FLASH_BLOCK_SIZE (64 * 1024)          // EXTERNAL_FLASH_SIZE / 256
#define EXTERNAL_FLASH_SIZE ((128 / 8) * 1024 * 1000)  // 128Mbit
#define EXTERNAL_FLASH_ADDRESS_SIZE 3                  // 0x000000 to 0xFFFFFF

// RGB configuration
// #define RGB_DI_PIN C6
// #define WS2812_PWM_DRIVER PWMD3
// #define WS2812_PWM_CHANNEL 1
// #define WS2812_PWM_PAL_MODE 2
// #define WS2812_DMA_STREAM STM32_DMA1_STREAM2
// #define WS2812_DMA_CHANNEL 5
// #define RGB_ENABLE_PIN C0

// ADC Configuration
// #define ADC_RESOLUTION ADC_CFGR1_RES_12BIT
// #define ADC_SATURATION ((1 << 12) - 1)
// #define ADC_CURRENT_PIN C5 // ADC12_IN15
// #define ADC_VOLTAGE_PIN B0 // ADC12_IN8

/* 
 * RGB Lighting Config
 */

#define RGB_DI_PIN C7
#define DRIVER_LED_TOTAL 5

#define RGB_DISABLE_WHEN_USB_SUSPENDED        // turn off effects when suspended
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180      // limits maximum brightness of LEDs to x out of 255. If not defined maximum brightness is set to 255
#define ENABLE_RGB_MATRIX_SOLID_COLOR         // Static single color
// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT // Static gradient left to right, speed controls how much gradient changes


// #define RGB_DI_PIN C7
// #define RGBLED_NUM 5               // 5 LED's present, 0 = Caps Lock and then key's 5678
// #define RGBLIGHT_HUE_STEP	8	   // The number of steps to cycle through the hue by
// #define RGBLIGHT_SAT_STEP	8	   // The number of steps to increment the saturation by
// #define RGBLIGHT_VAL_STEP	8	   // The number of steps to increment the brightness by
// #define RGBLIGHT_LIMIT_VAL	255	   // The maximum brightness level
// #define RGBLIGHT_SLEEP             // RGB lighting will be switched off when the host goes to sleep
// // #define RGBLIGHT_DISABLE_KEYCODES  // Disables the ability to control RGB Light from the keycodes
// #undef RGBLIGHT_ANIMATIONS

// #define RGBLIGHT_DEFAULT_MODE  RGBLIGHT_MODE_STATIC_LIGHT
// // #define RGBLIGHT_DEFAULT_HUE   0
// // #define RGBLIGHT_DEFAULT_SAT   0
// // #define RGBLIGHT_DEFAULT_VAL   0

// /* AUDIO */
// #define WS2812_PWM_DRIVER PWMD3
// #define WS2812_PWM_CHANNEL 1
// #define WS2812_PWM_PAL_MODE 2
// #define WS2812_DMA_STREAM STM32_DMA1_STREAM2
// #define WS2812_DMA_CHANNEL 5


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
