// Copyright 2023 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "tecsmith_common.h"
// #ifdef VIA_ENABLE
//     #include "vr61_via_config.h"
// #endif

__attribute__ ((weak)) tecsmith_kb_config_t ts_kb_config = { .raw = 0 };
uint32_t ts_keycode_raised = 0;

__attribute__ ((weak)) void load_kb_settings(void) {
    ts_kb_config.raw = eeconfig_read_kb();
}

__attribute__ ((weak)) void save_kb_settings(void) {
    // TODO: maybe delay the write with a timer?
    eeconfig_update_kb(ts_kb_config.raw);
}

__attribute__ ((weak)) bool get_arrow_mode(void) {
    return ts_kb_config.in_arrow_mode;
}

__attribute__ ((weak)) void set_arrow_mode(bool enabled) {
    ts_kb_config.in_arrow_mode = enabled;
    save_kb_settings();
}

void keyboard_post_init_tecsmith(void) {
    // Read the user config from EEPROM
    load_kb_settings();
    ts_keycode_raised = 0;
}

void eeconfig_init_tecsmith(void) {
    // EEPROM is getting reset!
    set_arrow_mode(false);
    save_kb_settings();
}

void housekeeping_task_tecsmith(void) {
    // do noting for now
}

static bool _process_record_code_2(keyrecord_t *record, uint16_t data1, uint16_t data2) {
    if (record->event.pressed) {
        register_code(data1);  
        register_code(data2);
    } else {
        unregister_code(data2);
        unregister_code(data1);
    }
    return false;  // Skip all further processing of this key
}

static bool _process_record_code_3(keyrecord_t *record, uint16_t data1, uint16_t data2, uint16_t data3) {
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

static bool _get_keycode_raised(uint8_t n) {
    return ts_keycode_raised & (1 << n);
}

static void _set_keycode_raised(uint8_t n, bool b) {
    if (b) {
        ts_keycode_raised |= (1 << n);
    } else {
        ts_keycode_raised &= ~(1 << n);
    }
}

static bool _process_record_special(uint16_t keycode, keyrecord_t *record, uint8_t key, uint8_t raised_key, uint8_t arrow, uint8_t raised_arrow) {
    bool is_raised;

    if (record->event.pressed) {

        is_raised = get_highest_layer(layer_state|default_layer_state) != 0;
        _set_keycode_raised(keycode - TS_KEY_START, is_raised);   // save for key release event

        if (!get_arrow_mode()) {
            if (!is_raised) {
                register_code( key );
            } else {
                register_code( raised_key );
            }
        } else {
            if (!is_raised) {
                register_code( arrow );
            } else {
                register_code( raised_arrow );
            }
        }

    } else {

        is_raised = _get_keycode_raised(keycode - TS_KEY_START);

        if (!get_arrow_mode()) {
            if (!is_raised) {
                unregister_code( key );
            } else {
                unregister_code( raised_key );
            }
        } else {
            if (!is_raised) {
                unregister_code( arrow );
            } else {
                unregister_code( raised_arrow );
            }
        }

    }
    return false;  // Skip all further processing of this key
}

bool process_record_tecsmith(uint16_t keycode, keyrecord_t *record) {

    uint8_t shifted = get_mods() & MOD_MASK_SHIFT;

    switch (keycode) {

        // *** Make all LED red on QK_BOOT / RESET

        #ifdef RGB_MATRIX_ENABLE
        case QK_BOOT:
            if (record->event.pressed) {
                rgb_matrix_set_color_all(RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, 0);  // All red
                rgb_matrix_driver.flush();
                wait_ms(10);
            }
            return true; break;
        #endif  // RGB_MATRIX_ENABLE

        // ** Handle Brighness when keycodes disabled

        #if (defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_DISABLE_KEYCODES)) || (defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_DISABLE_KEYCODES))
        case RGB_VAI:
            #ifdef RGBLIGHT_ENABLE
            if (shifted) { rgblight_increase_val(); } else { rgblight_decrease_val(); }
            #endif
            #ifdef RGB_MATRIX_ENABLE
            if (shifted) { rgb_matrix_increase_val(); } else { rgb_matrix_decrease_val(); }
            #endif
            return false;

        case RGB_VAD:
            #ifdef RGBLIGHT_ENABLE
            if (shifted) { rgblight_decrease_val(); } else { rgblight_increase_val(); }
            #endif
            #ifdef RGB_MATRIX_ENABLE
            if (shifted) { rgb_matrix_decrease_val(); } else { rgb_matrix_increase_val(); }
            #endif
            return false;

        #endif  // xxx_rgb_DISABLE_KEYCODES

        case KC_TASK_VIEW:     return _process_record_code_2(record, KC_LWIN, KC_TAB); break;
        case KC_FILE_EXPLORER: return _process_record_code_2(record, KC_LWIN, KC_E); break;
        case KC_CORTANA:       return _process_record_code_2(record, KC_LWIN, KC_C); break;
        case KC_SIRI:          return _process_record_code_2(record, KC_LOPT, KC_SPACE); break;
        case KC_SCREEN_SHOT:   return _process_record_code_3(record, KC_LSFT, KC_LCMD, KC_4); break;

        case KC_ARROW_MODE:
            if (record->event.pressed) {
                set_arrow_mode(!get_arrow_mode());
            }
            return false; break;

        case SPECIAL_RSFT_OR_UP:   return _process_record_special(keycode, record, KC_RSFT, KC_UP,   KC_UP,   KC_PGUP); break;
        case SPECIAL_RALT_OR_LEFT: return _process_record_special(keycode, record, KC_RALT, KC_LEFT, KC_LEFT, KC_HOME); break;
        case SPECIAL_RGUI_OR_LEFT: return _process_record_special(keycode, record, KC_RGUI, KC_LEFT, KC_LEFT, KC_HOME); break;
        case SPECIAL_RGUI_OR_DOWN: return _process_record_special(keycode, record, KC_RGUI, KC_DOWN, KC_DOWN, KC_PGDN); break;
        case SPECIAL_MENU_OR_DOWN: return _process_record_special(keycode, record, KC_APP,  KC_DOWN, KC_DOWN, KC_PGDN); break;
        case SPECIAL_RALT_OR_DOWN: return _process_record_special(keycode, record, KC_RALT, KC_DOWN, KC_DOWN, KC_PGDN); break;
        case SPECIAL_RCTL_OR_RGHT: return _process_record_special(keycode, record, KC_RCTL, KC_RGHT, KC_RGHT, KC_END ); break;

        case KC_RESET_EEPROM: 
            #ifdef RGB_MATRIX_ENABLE
            rgb_matrix_set_color_all(RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, RGB_MATRIX_MAXIMUM_BRIGHTNESS);  // Magenta
            rgb_matrix_driver.flush();
            wait_ms(10);
            #endif  // RGB_MATRIX_ENABLE
            eeconfig_init_quantum();
            soft_reset_keyboard();
            return false;
            break;
        
        case KC_VERSION_INFO:
            if (!record->event.pressed) {
                #if defined(VIA_ENABLE) || defined(VIAL_ENABLE)
                char str[6];
                #endif  // VIA_ENABLE || VIAL_ENABLE
                
                SEND_STRING_DELAY( QMK_KEYBOARD ":" QMK_KEYMAP " (QMK v" QMK_VERSION , 0 );

                #ifdef VIA_ENABLE
                sprintf(str, "%d", VIA_PROTOCOL_VERSION);
                SEND_STRING_DELAY( ", VIA v" , 0 );
                SEND_STRING_DELAY( str , 0);
                #endif  // VIA_ENABLE

                // #ifdef VIAL_ENABLE
                // sprintf(str, "%d", VIAL_PROTOCOL_VERSION);
                // SEND_STRING_DELAY( ", Vial v" , 0 );
                // SEND_STRING_DELAY( str , 0 );
                // #endif  // VIA_ENABLE

                SEND_STRING_DELAY( ")" , 0 );
            }
            return false;
            break;

        default:
            return true;  // Process all other keycodes normally
    }
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_tecsmith(uint8_t led_min, uint8_t led_max) {
    // do nothing for now
    return true;
}
#endif  // RGB_MATRIX_ENABLE


/*

bool vr61_consumer_send(keyrecord_t *record, uint16_t data) {
    if (record->event.pressed) {
        host_consumer_send(data);
    } else {
        host_consumer_send(0);
    }
    return false;  // Skip all further processing of this key
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // handle RGB toggle key - this ensures caps lock always works

        // macOS Mission Control
        // case KC_MCTL: return vr61_consumer_send(record, _AC_SHOW_ALL_WINDOWS); break;

        // macOS Launchpad
        // case KC_LPAD: return vr61_consumer_send(record, _AC_SHOW_ALL_APPS); break;

}  

*/
