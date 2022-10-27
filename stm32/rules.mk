# Copyright 2022 Vino Rodrigues (@vinorodrigues)
# SPDX-License-Identifier: GPL-3.0-or-later

LTO_ENABLE = no        # NEVER "yes" for ChibiOS mcu's

WS2812_DRIVER = pwm

FLASH_DRIVER = spi

OPT = g
OPT_DEFS += -g
