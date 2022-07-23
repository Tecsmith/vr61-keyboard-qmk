// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include_next "board.h"

#ifdef BOARD_OTG_NOVBUSSENS
    #undef BOARD_OTG_NOVBUSSENS
#endif
