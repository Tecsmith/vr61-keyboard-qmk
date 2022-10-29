# Copyright 2022 Vino Rodrigues (@vinorodrigues)
# SPDX-License-Identifier: GPL-3.0-or-later

OPT_DEFS += -DMICROMOD_RP2040  # #define

LTO_ENABLE = no  # NEVER "yes" for ChibiOS mcu's

WS2812_DRIVER = vendor

# Project specific files
QUANTUM_LIB_SRC += spi_master.c
