// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
// #define DYNAMIC_MACRO_SIZE 512

#undef FORCE_NKRO  // NKRO stops macOS Fn key functionality


/* VIAL */
#ifdef MICROMOD_STM32
    #define VIAL_KEYBOARD_UID {0xA6, 0x81, 0xDB, 0x0C, 0x1E, 0x60, 0x36, 0x01}
#elif MICROMOD_RP2040
    #define VIAL_KEYBOARD_UID {0xA6, 0x81, 0xDB, 0x0C, 0x1E, 0x60, 0x36, 0x02}
#elif  // undefined
    #error "Unknown Micromod module"
#endif  // MICROMOD_STM32 | MICROMOD_RP2040

#define VIAL_UNLOCK_COMBO_ROWS { 0, 7 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 6 }


/* Make Caps-Lock Tap/Hold Faster */
#undef TAPPING_TERM
#define TAPPING_TERM 150
#define PERMISSIVE_HOLD

#define VIA_EEPROM_ALLOW_RESET
// #define VIA_EEPROM_CUSTOM_CONFIG_SIZE 13

#ifdef ISO_ENABLE
    #define VIA_EEPROM_LAYOUT_OPTIONS_DEFAULT 0x03  // override of the layout options default value.
#endif
