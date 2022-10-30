// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "version.h"
// #include "post_config.h"

typedef union {
    uint32_t raw;
    struct {
        bool in_arrow_mode:1;
        // #ifdef RGB_MATRIX_ENABLE
        // uint8_t rgb_value;
        // #endif  // RGB_MATRIX_ENABLE
    };
} user_config_t;

enum {
    _L0,
    _L1,
    _L2,
    _L3,
    _L4
};

enum {
    KC_TSKV = USER00,  // Windows Task View
    KC_FEXP,           // Windows File Explorer
    KC_CORT,           // Windows Cortana
    KC_MCON,           // macOS Mission Control
    KC_LPAD,           // macOS Launchpad
    KC_SIRI,           // macOS Siri
    KC_SCAP,           // macOS Screen Capture
    KB_ARRW,           // toggle right modifiers are arrows feature
    KB_RSFT,           // right shift or up arrow
    KB_RALT,           // right alt or left arrow
    KB_RAPP,           // menu or down arrow (Windows Menu)
    KB_RCMD,           // right gui or left arrow (macOS Command)
    KB_ROPT,           // right alt or down arrow (macOS Option)
    KB_RCTL,           // right ctrl ot right arrow
    KB_REEP,           // Reset EEPROM -> Keymap to Defaul
    KB_VRSN            // debug, type version
};

enum {
    KC_PB01 = PROGRAMMABLE_BUTTON_1,
    KC_PB02 = PROGRAMMABLE_BUTTON_2,
    KC_PB03 = PROGRAMMABLE_BUTTON_3,
    KC_PB04 = PROGRAMMABLE_BUTTON_4,
    KC_PB05 = PROGRAMMABLE_BUTTON_5,
    KC_PB06 = PROGRAMMABLE_BUTTON_6,
    KC_PB07 = PROGRAMMABLE_BUTTON_7,
    KC_PB08 = PROGRAMMABLE_BUTTON_8,
    KC_PB09 = PROGRAMMABLE_BUTTON_9,
    KC_PB10 = PROGRAMMABLE_BUTTON_10
};

enum macos_consumer_usages {
    _AC_SHOW_ALL_WINDOWS = 0x29F,  // mapped to KC_MCON
    _AC_SHOW_ALL_APPS    = 0x2A0  // mapped to KC_LPAD
};

/* Special Keys */
#define SK_LT1C LT(_L1, KC_CAPS)  // Layer Tap 1, i.e., Tap = Caps Lock, Hold = Layer 1
#define SK_LT2A LT(_L2, KC_APP)  // Layer Tap 2, i.e., Tap = Menu, Hold = Layer 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│Ctrl│
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [_L0] = LAYOUT_60_ansi(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        SK_LT1C, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KB_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             MO(_L1), KB_RCMD, KB_ROPT, KB_RCTL
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
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KB_ARRW, _______, KC_UP,   _______, _______, _______, _______, _______, _______, RGB_VAI, KC_SCAP, KC_HOME, KC_END,  KC_INS,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, RGB_VAD, _______, KC_PGUP,          _______,
        _______,          _______, _______, _______, KB_VRSN, QK_BOOT, _______, _______, _______, _______, KC_PGDN,          _______,
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
        _______, KC_PB01, KC_PB02, KC_PB03, KC_PB04, KC_PB05, KC_PB06, KC_PB07, KC_PB08, KC_PB09, KC_PB10, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),

    [_L4] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )

};

user_config_t user_config;


/*
 * RGB Common
 */

#ifdef RGB_MATRIX_ENABLE

// #ifndef RGB_MATRIX_VAL_STEP
//     #define RGB_MATRIX_VAL_STEP 8
// #endif

#ifndef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 0xFF
#endif

void rgb_matrix_indicators_user() {
    // uint8_t v = user_config.rgb_value;
    uint8_t v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(0, v, v, v);
    }

    uint8_t current_layer = get_highest_layer(layer_state | default_layer_state);

    switch (current_layer) {
        case 1:
            for (uint8_t i = 1; i <= 4; i++) rgb_matrix_set_color(i, 0, 0, v);  // blue
            break;
        case 2:
            for (uint8_t i = 1; i <= 4; i++) rgb_matrix_set_color(i, 0, v, 0);  // green
            break;
        case 3:
            for (uint8_t i = 1; i <= 4; i++) rgb_matrix_set_color(i, v, 0, 0);  // red
            break;
        case 4:
            for (uint8_t i = 1; i <= 4; i++) rgb_matrix_set_color(i, v, v, 0);  // yellow
            break;
        default:
            break;
    }        
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

#endif  // RGB_MATRIX_ENABLE


/*
 * Keyboard Code
 */

bool delkey_registered = false;
uint32_t __keycode_raised = 0;

void keyboard_post_init_user(void) {
    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();

    #ifdef RGB_MATRIX_ENABLE
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
    #endif  // RGB_MATRIX_ENABLE
}

void eeconfig_init_user(void) {
    // EEPROM is getting reset!
    user_config.raw = 0;
    // #ifdef RGB_MATRIX_ENABLE
    // user_config.rgb_value = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
    // #endif  // RGB_MATRIX_ENABLE
    eeconfig_update_kb(user_config.raw);
}

bool __get_keycode_raised(uint8_t n) {
    return __keycode_raised & (1 << n);
}

void __set_keycode_raised(uint8_t n, bool b) {
    if (b) {
        __keycode_raised |= 1 << n;
    } else {
        __keycode_raised &= ~(1 << n);
    }
}

bool vr61_process_special_k(uint16_t keycode, keyrecord_t *record, bool arrow_mode, uint8_t k_norm, uint8_t k_spcl, uint8_t k_altr) {
    bool is_raised = get_highest_layer(layer_state|default_layer_state) != 0;

    if (record->event.pressed) {
        __set_keycode_raised(keycode - USER00, is_raised);  // save for key release event
        if (is_raised) {
            // *** Fn keyed ***
            if (arrow_mode) {
                // alternate key
                register_code(k_altr);
            } else {
                // special key
                register_code(k_spcl);
            }
        } else {
            // *** normal, un-Fn'ed ***
            if (arrow_mode) {
                // special key
                register_code(k_spcl);
            } else {
                // normal key
                register_code(k_norm);
            }
        }
    } else {
        if (__get_keycode_raised(keycode - USER00)) {
            // *** Fn keyed ***
            if (arrow_mode) {
                // alternate key
                unregister_code(k_altr);
            } else {
                // special key
                unregister_code(k_spcl);
            }
        } else {
            // *** normal, un-Fn'ed ***
            if (arrow_mode) {
                // special key
                unregister_code(k_spcl);
            } else {
                // normal key
                unregister_code(k_norm);
            }
        }
    }
    return false;
}

bool vr61_backspace_special(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();

    if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            register_code(KC_DEL);
            delkey_registered = true;
            set_mods(mod_state);
            return false;
        }
    } else {
        if (delkey_registered) {
            unregister_code(KC_DEL);
            delkey_registered = false;
            return false;
        }
    }
    return true;  // normal backspace, pass on
}

bool vr61_consumer_send(keyrecord_t *record, uint16_t data) {
    if (record->event.pressed) {
        host_consumer_send(data);
    } else {
        host_consumer_send(0);
    }
    return false;  // Skip all further processing of this key
}

bool vr61_code_2(keyrecord_t *record, uint16_t data1, uint16_t data2) {
    if (record->event.pressed) {
        register_code(data1);
        register_code(data2);
    } else {
        unregister_code(data2);
        unregister_code(data1);
    }
    return false;  // Skip all further processing of this key
}

bool vr61_code_3(keyrecord_t *record, uint16_t data1, uint16_t data2, uint16_t data3) {
    if (record->event.pressed) {
        register_code(data1);
        register_code(data2);
        register_code(data3);
    } else {
        unregister_code(data3);
        unregister_code(data2);
        unregister_code(data1);
    }
    return false;  // Skip all further processing of this key
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // handle RGB toggle key - this ensures caps lock always works
        #ifdef RGB_MATRIX_ENABLE

        case QK_BOOT:
            if (record->event.pressed) {
                rgb_matrix_set_color_all(RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, 0);  // All red
                rgb_matrix_driver.flush();
                wait_ms(10);
            }
            return true; break;

        // case RGB_VAI:
        //     if (user_config.rgb_value < RGB_MATRIX_MAXIMUM_BRIGHTNESS) {
        //         if (user_config.rgb_value + RGB_MATRIX_VAL_STEP > RGB_MATRIX_MAXIMUM_BRIGHTNESS) {
        //             user_config.rgb_value = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
        //         } else {
        //             user_config.rgb_value += RGB_MATRIX_VAL_STEP;
        //         }
        //         eeconfig_update_kb(user_config.raw);
        //     }
        //     return false;
        //     break;

        // case RGB_VAD:
        //     if (user_config.rgb_value > RGB_MATRIX_VAL_STEP) {
        //         // cannot be 0, minimum = RGB_MATRIX_VAL_STEP
        //         if (user_config.rgb_value - RGB_MATRIX_VAL_STEP < RGB_MATRIX_VAL_STEP) {
        //             user_config.rgb_value = RGB_MATRIX_VAL_STEP;
        //         } else {
        //             user_config.rgb_value -= RGB_MATRIX_VAL_STEP;
        //         }
        //         eeconfig_update_kb(user_config.raw);
        //     }
        //     return false;
        //     break;

        #endif  // RGB_MATRIX_ENABLE

        // Shift + Backspace = Delete, see: https://docs.qmk.fm/#/feature_advanced_keycodes?id=shift-backspace-for-delete
        case KC_BSPC: return vr61_backspace_special(keycode, record); break;

        // Windows Task View
        case KC_TSKV: return vr61_code_2(record, KC_LWIN, KC_TAB); break;

        // Windows File Explorer
        case KC_FEXP: return vr61_code_2(record, KC_LWIN, KC_E); break;

        // Windows Cortana
        case KC_CORT: return vr61_code_2(record, KC_LWIN, KC_C); break;

        // macOS Mission Control
        case KC_MCON: return vr61_consumer_send(record, _AC_SHOW_ALL_WINDOWS); break;

        // macOS Launchpad
        case KC_LPAD: return vr61_consumer_send(record, _AC_SHOW_ALL_APPS); break;

        // macOS Siri
        case KC_SIRI: return vr61_code_2(record, KC_LOPT, KC_SPACE);

        // macOS Screen Capture
        case KC_SCAP: return vr61_code_3(record, KC_LSFT, KC_LCMD, KC_4);

        // toggle right modifiers are arrows feature
        case KB_ARRW:           
            if (record->event.pressed) {
                user_config.in_arrow_mode ^= 1;
                eeconfig_update_kb(user_config.raw);
            }
            return false; break;

        // right shift or up arrow
        case KB_RSFT: return vr61_process_special_k(keycode, record, user_config.in_arrow_mode, KC_RSFT, KC_UP, KC_PGUP); break;

        // right alt or left arrow
        case KB_RALT: return vr61_process_special_k(keycode, record, user_config.in_arrow_mode, KC_RALT, KC_LEFT, KC_HOME); break;

        // menu or down arrow (Windows Menu)
        case KB_RAPP: return vr61_process_special_k(keycode, record, user_config.in_arrow_mode, KC_APP, KC_DOWN, KC_PGDN); break;

        // right gui or left arrow (macOS Command)
        case KB_RCMD: return vr61_process_special_k(keycode, record, user_config.in_arrow_mode, KC_RGUI, KC_LEFT, KC_HOME); break;

        // right alt or down arrow (macOS Option)// right alt or down arrow (macOS Option)
        case KB_ROPT: return vr61_process_special_k(keycode, record, user_config.in_arrow_mode, KC_RALT, KC_DOWN, KC_PGDN); break;

        // right ctrl ot right arrow
        case KB_RCTL: return vr61_process_special_k(keycode, record, user_config.in_arrow_mode, KC_RCTL, KC_RIGHT, KC_END); break;

        // Reset EEPROM -> Keymap to Defaul
        case KB_REEP:           
            rgb_matrix_set_color_all(RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
            rgb_matrix_driver.flush();
            wait_ms(10);
            eeconfig_init_quantum();
            soft_reset_keyboard();
            return false;

        // debug, type version
        case KB_VRSN:            
            if (!get_mods()) {
                if (!record->event.pressed) {
                    SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP " (v" QMK_VERSION ")");
                }
            }
            return false;

        default:
            return true; /* Process all other keycodes normally */
    }
}
