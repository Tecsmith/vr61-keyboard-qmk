// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-2.0-or-later
// ***** COMMON config.h FILE *****

#pragma once

/*
 * RGB Lighting Config
 */

#if defined(RGB_MATRIX_ENABLE)
    // ---------- RGB common ----------

    // Timing for SK6812
    #define WS2812_TRST_US 128

    #define WS2812_TIMING 1280
    #define WS2812_T0H    320
    #define WS2812_T0L	  (WS2812_TIMING - WS2812_T0H)
    #define WS2812_T1H	  640
    #define WS2812_T1L	  (WS2812_TIMING - WS2812_T1H)

    #define CAPS_LOCK_LED_INDEX 0

    #define RGB_MATRIX_LED_COUNT 5
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180  // limits maximum brightness of LEDs to x out of 255. If not defined maximum brightness is set to 255
    #define RGB_MATRIX_DEFAULT_VAL (RGB_MATRIX_MAXIMUM_BRIGHTNESS)  // Sets the default brightness value, if none has been set

    #ifdef RGB_MATRIX_ENABLE
        #define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
        #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR  // Sets the default mode, if none has been set
        #define RGB_MATRIX_DEFAULT_HUE 0  // Sets the default hue value, if none has been set
        #define RGB_MATRIX_DEFAULT_SAT 0  // Sets the default saturation value, if none has been set
        // #define RGB_MATRIX_DEFAULT_SPD 0

        #define RGB_MATRIX_DISABLE_KEYCODES  // disables control of rgb matrix by keycodes (must use code functions to control the feature)
    #endif
#endif  // RGB_MATRIX_ENABLE
