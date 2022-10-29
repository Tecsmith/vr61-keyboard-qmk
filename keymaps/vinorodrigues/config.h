// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

// #define DYNAMIC_KEYMAP_LAYER_COUNT 4
// #define DYNAMIC_MACRO_SIZE 512

#undef FORCE_NKRO  // NKRO stops macOS Fn key functionality

#ifdef MICROMOD_STM32
    #define VIAL_KEYBOARD_UID {0xA6, 0x81, 0xDB, 0x0C, 0x1E, 0x60, 0x36, 0xEC}
#elif MICROMOD_RP2040
    #define VIAL_KEYBOARD_UID {0xDA, 0xDF, 0xDB, 0xD5, 0xB2, 0xB7, 0x0F, 0xEB}
#elif
    #error "Unknown Micromod module"
#endif  // MICROMOD_STM32 or MICROMOD_RP2040

#define VIAL_UNLOCK_COMBO_ROWS { 0, 7 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 6 }

/* Make Caps-Lock Tap/Hold Faster */
#undef TAPPING_TERM
#define TAPPING_TERM 150
