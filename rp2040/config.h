// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later
// ***** RP2040 config.h FILE *****

#pragma once

/*
 * SPI Configuration & External Flash
 */

#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20


/* 
 * RGB Matrix Config
 */

#ifdef RGB_MATRIX_ENABLE
    // The pin connected to the data pin of the LEDs
    #define RGB_DI_PIN GP13
    // #define NOP_FUDGE 0.4

    // Timing for SK6812
    #undef WS2812_TIMING
    #undef WS2812_T0H
    #undef WS2812_T0L
    #undef WS2812_T1H
    #undef WS2812_T1L
    // Overrides as per: https://discord.com/channels/798171334756401183/798171873951219754/1061408936680488980
    // "For the RP2040, just change WS2812_TIMING, WS2812_T1H, WS2812_T0H and WS2812_TRST_US to the timings that
    //  your sk68** states in the datasheet. Time resolution is accurate down to 50us steps. The vendor driver
    //  got a big overhaul in the last breaking change merge." - @KarlK90
    #define WS2812_TIMING 1250
    #define WS2812_T0H    350
    #define WS2812_T0L	  (WS2812_TIMING - WS2812_T0H)
    #define WS2812_T1H	  650
    #define WS2812_T1L	  (WS2812_TIMING - WS2812_T1H)

#endif  // RGB_MATRIX_ENABLE


/*
 * ADC Configuration
 */

// #define ADC_RESOLUTION ? ? ? // ADC_CFGR1_RES_12BIT // TBD when RP2040 has analog support
// #define ADC_SATURATION ? ? ? // ((1 << 12) - 1) // TBD when RP2040 has analog support
// #define ADC_CURRENT_PIN GP26


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
