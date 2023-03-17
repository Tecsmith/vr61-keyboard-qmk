// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
// #define DYNAMIC_MACRO_SIZE 512

#undef FORCE_NKRO  // NKRO stops macOS Fn key functionality

/* Make Caps-Lock Tap/Hold Faster */
#undef TAPPING_TERM
#define TAPPING_TERM 150
#define PERMISSIVE_HOLD

#define VIA_EEPROM_ALLOW_RESET
#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 13