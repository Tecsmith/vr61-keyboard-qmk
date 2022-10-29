// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later
// ***** RP2040 config.h FILE *****

#pragma once

#include "config_common.h"


/*
 * SPI Configuration
 */

#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20


/* 
 * PR2040 MCU stuff
 */

// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U


/* 
 * RGB Lighting/Matrix Config
 */

#ifdef RGB_MATRIX_ENABLE
    // The pin connected to the data pin of the LEDs
    #define RGB_DI_PIN GP13
    #define NOP_FUDGE 0.4
#endif  // RGB_MATRIX_ENABLE


/*
 * ADC Configuration
 */

#define ADC_RESOLUTION ? ? ? // ADC_CFGR1_RES_12BIT // TBD when RP2040 has analog support
#define ADC_SATURATION ? ? ? // ((1 << 12) - 1) // TBD when RP2040 has analog support
#define ADC_CURRENT_PIN GP26


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
