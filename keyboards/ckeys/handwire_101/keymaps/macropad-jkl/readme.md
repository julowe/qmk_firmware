# A macropad keymap for the cKeys Handwire 101 4x4 keyboard.
Made by jkl 20201218

## Building & Flashing
Reminder, this worked at one point: 
`make ckeys/handwire_101:macropad-jkl EXTRAFLAGS+=--specs=nosys.specs`
`dfu-util -S 206E35692032 -s 0x08000000 -a 0 -D ckeys_handwire_101_macropad-jkl_proton_c.bin`
