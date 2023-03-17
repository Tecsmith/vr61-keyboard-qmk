# Copyright 2022 Vino Rodrigues (@vinorodrigues)
# SPDX-License-Identifier: GPL-3.0-or-later

OPT_DEFS += -DMICROMOD_STM32

LTO_ENABLE = no  # NEVER "yes" for ChibiOS mcu's

WS2812_DRIVER = pwm

FLASH_DRIVER = spi

EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = embedded_flash

OPT = g
OPT_DEFS += -g

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE  # Enter lower-power sleep mode when on the ChibiOS idle thread

VPATH += keyboards/tecsmith/vr61/common
