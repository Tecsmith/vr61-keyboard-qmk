// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

/*
 * EFL/WL Driver Configuration
 */

#define WEAR_LEVELING_LOGICAL_SIZE 4096                              // Number of bytes "exposed" to the rest of QMK and denotes the size of the usable EEPROM.
#define WEAR_LEVELING_BACKING_SIZE (WEAR_LEVELING_LOGICAL_SIZE * 2)  // Number of bytes used by the wear-leveling algorithm for its underlying storage, and needs to be a multiple of the logical size.


/*
 * SPI Configuration & External Flash
 */

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

/*
 * RGB Matrix Config
 */

#ifdef RGB_MATRIX_ENABLE
    // The pin connected to the data pin of the LEDs
    #define RGB_DI_PIN C6

    #define WS2812_PWM_DRIVER PWMD3
    #define WS2812_PWM_CHANNEL 1
    #define WS2812_PWM_PAL_MODE 2
    #define WS2812_DMA_STREAM STM32_DMA1_STREAM2
    #define WS2812_DMA_CHANNEL 5
    // #define RGB_ENABLE_PIN C0
#endif  // RGB_MATRIX_ENABLE


/*
 * ADC Configuration
 */

// #define ADC_RESOLUTION ADC_CFGR1_RES_12BIT
// #define ADC_SATURATION ((1 << 12) - 1)
// #define ADC_CURRENT_PIN C5 // ADC12_IN15


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
