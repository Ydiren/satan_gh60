# Satan GH60

Firmware project for the Satan gh60 board based on [tkg](https://github.com/kairyu/tkg-toolkit), [kairyu's fork](https://github.com/kairyu/tmk_keyboard_custom) of [tmk_keyboard](https://github.com/tmk/tmk_keyboard), and [tofagerl's gist](https://gist.github.com/tofagerl/7182f2c6dd803a68b952)

## Setup

Install `dfu-programmer`, `avr-gcc`, `avr-libc`, and `make`

## Keymaps

Drop a keymap file in `keymaps/` named `foo.c`. See [`tmk/tmk_core/doc/keymap.md`](https://github.com/tmk/tmk_keyboard/blob/master/tmk_core/doc/keymap.md) for details on keymap configurations.

## Compiling and Installing

If you want to compile and install all at once, run:

```
make KEYMAP=foo all
```

### Compiling

To compile the keymap to a `.hex` file (located in `firmware/`), run:  

```
make KEYMAP=foo
```

### Installing

To install the keymap, run:

```
make KEYMAP=foo install
```

During the install process you'll be asked to confirm. Just press Enter.

When it says `Waiting for Bootloader...`, press the button on the bottom of your keyboard.
