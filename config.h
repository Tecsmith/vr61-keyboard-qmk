// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-2.0-or-later
// ***** COMMON config.h FILE *****

#pragma once

// The number of LEDs connected
#define DRIVER_LED_TOTAL 5

/* 
 * RGB Lighting Config
 */

// ---------- RGB common ---------- ---------- ----------
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)

    // Timing for SK6812
    #define WS2812_TRST_US 128

    #define WS2812_TIMING 1280
    #define WS2812_T0H 320
    #define WS2812_T0L	WS2812_TIMING - WS2812_T0H
    #define WS2812_T1H	640
    #define WS2812_T1L	WS2812_TIMING - WS2812_T1H

#endif  // RGBLIGHT_ENABLE || RGB_MATRIX_ENABLE

// ---------- RGB Lighting library ---------- ---------- ----------
#ifdef RGBLIGHT_ENABLE

    #define RGBLED_NUM 5

    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
    #define RGBLIGHT_LIMIT_VAL 180
    #define RGBLIGHT_SLEEP
    // #define RGBLIGHT_DISABLE_KEYCODES                // disables the ability to control RGB Light from the keycodes.
    // #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
    // #define RGBLIGHT_DEFAULT_HUE 0                   // default hue to use
    // #define RGBLIGHT_DEFAULT_SAT UINT8_MAX           // default saturation to use
    // #define RGBLIGHT_DEFAULT_VAL RGBLIGHT_LIMIT_VAL  // default value (brightness) to use
    // #define RGBLIGHT_DEFAULT_SPD	0                   // default speed to use 

#endif  // RGBLIGHT_ENABLE

// ---------- RGB Matri library ---------- ---------- ----------
#ifdef RGB_MATRIX_ENABLE

    #define RGB_DISABLE_WHEN_USB_SUSPENDED                       // turn off effects when suspended
    // #define RGB_MATRIX_LED_FLUSH_LIMIT 16                        // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180                    // limits maximum brightness of LEDs to x out of 255. If not defined maximum brightness is set to 255
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR       // Sets the default mode, if none has been set
    #define RGB_MATRIX_STARTUP_HUE 0                             // Sets the default hue value, if none has been set
    #define RGB_MATRIX_STARTUP_SAT 0                             // Sets the default saturation value, if none has been set
    #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
    // #define RGB_MATRIX_STARTUP_SPD 127                           // Sets the default animation speed, if none has been set
    #define RGB_MATRIX_DISABLE_KEYCODES                          // disables control of rgb matrix by keycodes (must use code functions to control the feature)
    #define RGB_TRIGGER_ON_KEYDOWN                               // Triggers RGB keypress events on key down. This makes RGB control feel more responsive. This may cause RGB to not function properly on some boards

    #define ENABLE_RGB_MATRIX_SOLID_COLOR         // Static single color

#endif  // RGB_MATRIX_ENABLE
