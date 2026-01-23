# SR61 - Swappable Microcontroller Custom Keyboard

*SR61 MicroMod Keyboard PCB utilizing the Sparkfun STM32 MicroMod module*

## ANSI 61-key Layout

* Keyboard Maintainer: [SilvinoR](https://github.com/silvinor)
* Hardware Supported: [**SR61 PCB**](https://github.com/Tecsmith/sr61-keyboard-pcb) + Sparkfun Micromod STM32 or Micromod RP2040 module
* Hardware Availability: [BYO, Gerbers and BOMs on Github](https://github.com/Tecsmith/sr61-keyboard-pcb)

Make example for this keyboard (after setting up your build environment):

    make tecsmith/sr61/stm32:default
    make tecsmith/sr61/rp2040:default

Flashing example for this keyboard:

    make tecsmith/sr61/stm32:default:flash
    make tecsmith/sr61/rp2040:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB, or short out the pads adjacent to the space bar switch location
* **Keycode in layout**: Press the key mapped to `RESET` if it is available *(default is **[Fn]**+**[Z]**)*
