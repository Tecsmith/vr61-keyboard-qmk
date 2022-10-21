// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

// #define DYNAMIC_KEYMAP_LAYER_COUNT 4
// #define DYNAMIC_MACRO_SIZE 512

#ifdef RGB_MATRIX_ENABLE
    #ifndef VIA_QMK_RGBLIGHT_ENABLE  // safe to remove after Q2-2022 `develop` PR
        #define VIA_QMK_RGBLIGHT_ENABLE
    #endif  // VIA_QMK_RGBLIGHT_ENABLE
#endif  // RGB_MATRIX_ENABLE
