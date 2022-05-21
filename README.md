# VR61 *"Goldilocks"* PCB

![]()

*VR61 MicroMod Keyboard PCB utilizing the Sparkfun STM32 MicroMod module*

## ANSI 61-key Layout

* Keyboard Maintainer: [vinorodrigues](https://github.com/vinorodrigues)
* Hardware Supported: **VR61 "Goldilocks" PCB**
* Hardware Availability: [Github](https://github.com/Tecsmith/vr61-keyboard-pcb)

Make example for this keyboard (after setting up your build environment):

    make sparkfun/vr61:default

Flashing example for this keyboard:

    make sparkfun/vr61:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB, or short out the pads adjacent to the space bar switch location
* **Keycode in layout**: Press the key mapped to `RESET` if it is available *(default is **[Fn]**+**[Z]**)*
