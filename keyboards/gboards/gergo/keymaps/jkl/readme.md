# [Gergo! By g Heavy Industries](http://gboards.ca)

![Gergo image](https://4.bp.blogspot.com/-889nMXxgSM0/XCNxwnO5kUI/AAAAAAAA6mI/tZbWgZVCBW0dyZOCGJDkjN06DVax7j8XwCLcBGAs/s1600/48422820_967732713413298_485744639215665152_n.jpg)

This is the default keymap for Gergo, it's based heavily off of the
naps62 ErgoDox layout and is aimed at a programmer friendly keymap.

## Settings

To edit various settings, enable the 1u trackball and whatnot please modify
/keyboards/gboards/gergo/keymaps/default/rules.mk

Ideally you should copy this directory and make your changes there.
If you come up with a good layout submit a PR!

## Updating Keyboard

Use qmk's tools - install with:
`python3 -m pip install --user qmk` and then `qmk setup`

then `qmk flash -kb gboards/gergo -km jkl` or the under-the-hood command:
`make gboards/gergo:jkl:flash`
then when qmk/dfu is waiting for the bootloader mode of the keyboard,
hit the reset button near usb socket.

You can also first test building the firmware with:
`make gboards/gergo:jkl`
