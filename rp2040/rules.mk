# Copyright 2022 Vino Rodrigues (@vinorodrigues)
# SPDX-License-Identifier: GPL-3.0-or-later

LTO_ENABLE = no        # NEVER "yes" for ChibiOS mcu's

# RGBLIGHT_ENABLE = yes  # .. or ..
# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = WS2812

# Project specific files
QUANTUM_LIB_SRC += spi_master.c
