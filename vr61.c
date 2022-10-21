// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "vr61.h"

#ifdef RGB_MATRIX_ENABLE

#define __ NO_LED

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    { __, __, __, __, __,  1,  2,  3 },
    { __, __, __, __, __, __, __, __ },
    {  0, __, __, __, __, __, __, __ },
    { __, __, __, __, __, __, __, __ },
    { __, __, __, __, __, __, __, __ },
    {  4, __, __, __, __, __, __, __ },
    { __, __, __, __, __, __, __, __ },
    { __, __, __, __, __, __, __, __ },
    { __, __, __, __, __, __, __, __ }
}, {
    // LED Index to Physical Position
    {  80, 0  }, {  96, 0  }, { 112, 0  }, { 128, 0  },
    {   6, 32 }
}, {
    // LED Index to Flag
    // MODIFIER = 0x01, UNDERGLOW = 0x02, KEYLIGHT = 0x04, & INDICATOR = 0x08
    0x04, 0x04, 0x04, 0x04,
    0x0C
} };

#endif  // RGB_MATRIX_ENABLE
