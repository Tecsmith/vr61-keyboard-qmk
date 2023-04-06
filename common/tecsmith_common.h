// Copyright 2023 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include QMK_KEYBOARD_H
#include "stdint.h"
#include "stdio.h"
#ifdef VIA_ENABLE
    #include "via.h"
#endif
#include "version.h"
#include "quantum_keycodes.h"

typedef union {
    uint32_t raw;
    struct {
        bool in_arrow_mode:1;
    };
} tecsmith_kb_config_t;

#ifdef MAKING_IN_VIAL
    #define TS_KEY_START USER00
#else
    #define TS_KEY_START QK_KB_0
#endif

enum {
    KC_TASK_VIEW = TS_KEY_START,  // Windows Task View
    KC_FILE_EXPLORER,             // Windows File Explorer
    KC_CORTANA,                   // Windows Cortana
    KC_SIRI,                      // macOS Siri
    KC_SCREEN_SHOT,               // macOS Screen Capture
    KC_ARROW_MODE,                // toggle right modifiers are arrows feature

    SPECIAL_RSFT_OR_UP,           // KC_RSFT or KC_UP
    SPECIAL_RALT_OR_LEFT,         // KC_RALT or KC_LEFT
    SPECIAL_RGUI_OR_LEFT,         // KC_RGUI or KC_LEFT
    SPECIAL_RGUI_OR_DOWN,         // KC_RGUI or KC_DOWN
    SPECIAL_MENU_OR_DOWN,         // KC_MENU or KC_DOWN
    SPECIAL_RALT_OR_DOWN,         // KC_RALT or KC_DOWN
    SPECIAL_RCTL_OR_RGHT,         // KC_RCTL or KC_RGHT

    KC_RESET_EEPROM,              // Reset EEPROM -> Keymap to Defaul
    KC_VERSION_INFO               // debug, type version
};

// short versions of the above enums

#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
#define KC_CRTA KC_CORTANA
#define KC_SNAP KC_SCREEN_SHOT
#define KC_ARRW KC_ARROW_MODE

#define SP_RSFT SPECIAL_RSFT_OR_UP
#define SP_RALF SPECIAL_RALT_OR_LEFT
#define SP_RWLF SPECIAL_RGUI_OR_LEFT
#define SP_RWDN SPECIAL_RGUI_OR_DOWN
#define SP_RMDN SPECIAL_MENU_OR_DOWN
#define SP_RADN SPECIAL_RALT_OR_DOWN
#define SP_RCTL SPECIAL_RCTL_OR_RGHT

#define KC_REEP KC_RESET_EEPROM
#define KC_VRSN KC_VERSION_INFO

void load_kb_settings(void);
void save_kb_settings(void);
bool get_arrow_mode(void);
void set_arrow_mode(bool enabled);

void keyboard_post_init_tecsmith(void);
void eeconfig_init_tecsmith(void);

void housekeeping_task_tecsmith(void);
bool process_record_tecsmith(uint16_t keycode, keyrecord_t *record);

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_tecsmith(uint8_t led_min, uint8_t led_max);
#endif  // RGB_MATRIX_ENABLE
