// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include_next <mcuconf.h>

// Used for External Flash
#undef STM32_SPI_USE_SPI1
#define STM32_SPI_USE_SPI1 TRUE

// Used for ADC
// #undef STM32_ADC_USE_ADC1
// #define STM32_ADC_USE_ADC1 TRUE

// Used for RGB
#undef STM32_PWM_USE_TIM3
#define STM32_PWM_USE_TIM3 TRUE
