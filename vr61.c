// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "quantum.h"

#ifndef CAPS_LOCK_LED_INDEX
    #error CAPS_LOCK_LED_INDEX is needed
#endif 

extern void rgb_matrix_update_pwm_buffers(void);

void keyboard_post_init_kb(void) {
    keyboard_post_init_user();

    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);    
}

__attribute__ ((weak)) RGB get_caps_lock_indicator_color(void) {
    HSV hsv = { .h = 0, .s = 0, .v = RGB_MATRIX_MAXIMUM_BRIGHTNESS};  // white
    RGB rgb = hsv_to_rgb( hsv );
    return rgb;
}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        RGB rgb = get_caps_lock_indicator_color();
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, rgb.r, rgb.g, rgb.b);
    }
    return true;
}

void rgb_matrix_indicators_none_kb(void) {
    rgb_matrix_indicators_kb();
    rgb_matrix_update_pwm_buffers();
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);

    if (rgb_matrix_is_enabled()
#    if defined(ENABLE_RGB_MATRIX_RAINDROPS)
        && (rgb_matrix_get_mode() != RGB_MATRIX_RAINDROPS)
#    endif
#    if defined(ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS)
        && (rgb_matrix_get_mode() != RGB_MATRIX_JELLYBEAN_RAINDROPS)
#    endif
#    if defined(ENABLE_RGB_MATRIX_PIXEL_RAIN)
        && (rgb_matrix_get_mode() != RGB_MATRIX_PIXEL_RAIN)
#    endif
    ) {
        return res;
    }

    if (res) {
        if (led_state.caps_lock) {
            RGB rgb = get_caps_lock_indicator_color();
            rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, rgb.r, rgb.g, rgb.b);
        } else {
            rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, 0, 0, 0);
        }
        rgb_matrix_update_pwm_buffers();
    }

    return res;
}
