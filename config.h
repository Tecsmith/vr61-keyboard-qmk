// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

// Matrix configuration
#define SPI_MATRIX_CHIP_SELECT_PIN C4
#define SPI_MATRIX_DIVISOR 32

/*
 * SPI Configuration
 * - used for EEPROM
 */
// #define SPI_DRIVER SPID1
// #define SPI_SCK_PIN A5
// #define SPI_SCK_PAL_MODE 5
// #define SPI_MOSI_PIN A6
// #define SPI_MOSI_PAL_MODE 5
// #define SPI_MISO_PIN A7
// #define SPI_MISO_PAL_MODE 5

#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN C3

#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 16 // (168MHz/16) => 10.5MHz
#define EXTERNAL_EEPROM_BYTE_COUNT 8192
#define EXTERNAL_EEPROM_PAGE_SIZE 64 // it's FRAM, so it doesn't actually matter, this just sets the RAM buffer


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
