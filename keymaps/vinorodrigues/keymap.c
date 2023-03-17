// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "tecsmith_common.h"

// clang-format off

enum {
    _L0,
    _L1,
    _L2,
    _L3,
    _L4
};

enum {
    MACRO00 = QK_MACRO_0,
    MACRO01 = QK_MACRO_1,
    MACRO02 = QK_MACRO_2,
    MACRO03 = QK_MACRO_3,
    MACRO04 = QK_MACRO_4,
    MACRO05 = QK_MACRO_5,
    MACRO06 = QK_MACRO_6,
    MACRO07 = QK_MACRO_7,
    MACRO08 = QK_MACRO_8,
    MACRO09 = QK_MACRO_9,
    MACRO10 = QK_MACRO_10,
    MACRO11 = QK_MACRO_11,
    MACRO12 = QK_MACRO_12,
    MACRO13 = QK_MACRO_13,
    MACRO14 = QK_MACRO_14,
    MACRO15 = QK_MACRO_15
};

/* Special Keys */
#define SK_LT1C LT(_L1, KC_CAPS)  // Layer Tap 1, i.e., Tap = Caps Lock, Hold = Layer 1
#define SK_LT2A LT(_L2, KC_APP)  // Layer Tap 2, i.e., Tap = Menu, Hold = Layer 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │Ctrl│GUI │Alt │                        │ Fn1 │Alt │GUI │Ctrl│    * GUI / Alt swapped for Mac
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [_L0] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        SK_LT1C, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          SP_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             MO(_L1), SP_RWLF, SP_RADN, SP_RCTL
    ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │        │   │   │   │   │   │   │   │   │   │   │          │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │    │    │    │                        │    │    │    │    │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [_L1] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        KC_ARRW, _______, KC_UP,   _______, _______, _______, _______, _______, RGB_VAI, KC_VOLU, KC_SNAP, KC_HOME, KC_END,  _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, RGB_VAD, KC_VOLD, KC_PGUP, KC_PGDN,          _______,
        _______,          _______, _______, _______, KC_VRSN, _______, _______, _______, _______, KC_INS,  KC_DEL,           _______,
        MO(_L4), MO(_L3), MO(_L2),                            _______,                            _______, _______, _______, _______
    ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │        │   │   │   │   │   │   │   │   │   │   │          │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │    │    │    │                        │    │    │    │    │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [_L2] = LAYOUT_60_ansi(
        MACRO00, MACRO01, MACRO02, MACRO03, MACRO04, MACRO05, MACRO06, MACRO07, MACRO08, MACRO09, MACRO10, MACRO11, MACRO12, MACRO13,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │        │   │   │   │   │   │   │   │   │   │   │          │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │    │    │    │                        │    │    │    │    │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [_L3] = LAYOUT_60_ansi(
        _______, PB_1,    PB_2,    PB_3,    PB_4,    PB_5,    PB_6,    PB_7,    PB_8,    PB_9,    PB_10,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),

    [_L4] = LAYOUT_60_ansi(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_REEP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )

};

/*
 * Key Overrides
 */

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_GUI, KC_ESC, KC_GRV);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &tilde_esc_override,
    &grave_esc_override,
    NULL  // Null terminate the array of overrides!
};

// clang-format on

void keyboard_post_init_user(void) {
    keyboard_post_init_tecsmith();
}

void eeconfig_init_user(void) {
    eeconfig_init_tecsmith();
}

void housekeeping_task_user(void) {
    housekeeping_task_tecsmith();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_tecsmith(keycode, record)) {
        return false;
    }
    return true;
}

/* 
 * RGB
 */

#if defined(RGB_MATRIX_ENABLE) && defined(VIA_ENABLE)

static void _rgb_matrix_set_color_1to4(uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = 1; i <= 4; i++) {
        rgb_matrix_set_color(i, red, green, blue);
    }
}

__attribute__ ((weak)) RGB get_layer_indicator_color(uint8_t layer) {
    HSV hsv = { .h = 0, .s = 0, .v = RGB_MATRIX_MAXIMUM_BRIGHTNESS};
    switch (layer) {
        case 0: hsv.v = 0;                        // #000000 black
        case 1: hsv.h = 170; hsv.s = 255; break;  // #0000FF blue
        case 2: hsv.h = 85; hsv.s = 255; break;   // #00FF00 green
        case 3: hsv.h = 213; hsv.s = 255; break;  // #FF00FF magenta
        case 4: hsv.h = 43; hsv.s = 255; break;   // #FFFF00 yellow
    }
    RGB rgb = hsv_to_rgb( hsv );
    return rgb;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if(!rgb_matrix_indicators_advanced_tecsmith(led_min, led_max)) {
        return false;
    }

    RGB rgb = { .r = 0, .g = 0, .b = 0 };
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _L0: rgb = get_layer_indicator_color(0); break;
        case _L1: rgb = get_layer_indicator_color(1); break;
        case _L2: rgb = get_layer_indicator_color(2); break;
        case _L3: rgb = get_layer_indicator_color(3); break;
        case _L4: rgb = get_layer_indicator_color(4); break;
    }
    _rgb_matrix_set_color_1to4(rgb.r, rgb.g, rgb.b);

    return true;
}

#endif  // RGB_MATRIX_ENABLE & VIA_ENABLE
