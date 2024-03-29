// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

// #define HAL_USE_ADC TRUE
#define HAL_USE_SPI TRUE  // Used for External FLASH
#define HAL_USE_PWM TRUE

#include_next <halconf.h>
