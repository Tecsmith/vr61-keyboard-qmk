// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later
// ***** RP2040 config.h FILE *****

#pragma once

/* 
 * PR2040 MCU stuff
 */

#define QMK_WAITING_TEST_BUSY_PIN GP8
#define QMK_WAITING_TEST_YIELD_PIN GP9

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U


/* 
 * RGB Lighting/Matrix Config
 */

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    // The pin connected to the data pin of the LEDs
    #define RGB_DI_PIN GP13
    #define NOP_FUDGE 0.4
#endif  // RGB_MATRIX_ENABLE


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
