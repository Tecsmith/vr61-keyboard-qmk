// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "vr61.h"

#define __ NO_LED

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { __, __, __, __, __, 1,  2,  3,  __ },
  { __, __, __, __, __, __, __, __, __ },
  { 0,  __, __, __, __, __, __, __, __ },
  { __, __, __, __, __, __, __, __, __ },
  { __, __, __, __, __, __, __, __, __ },
  { 4,  __, __, __, __, __, __, __, __ },
  { __, __, __, __, __, __, __, __, __ },
  { __, __, __, __, __, __, __, __, __ }
}, {
  // LED Index to Physical Position
  {  6,32 }, { 81,0  }, { 97,0  }, {113,0  }, {129,0  }
}, {
  // LED Index to Flag
  10, 2, 2, 2, 2
} };
