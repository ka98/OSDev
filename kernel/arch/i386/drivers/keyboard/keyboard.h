#ifndef ARCH_I386_DRIVERS_KEYBOARD_KEYBOARD_H
#define ARCH_I386_DRIVERS_KEYBOARD_KEYBOARD_H

#include <stddef.h>
#include <stdint.h>

//Port-adresses
#define KBC_STATE_COMMAND_PORT 0x64
#define KBC_IO_BUFFER_PORT 0x60

//Keyboard-Commands
#define KEYBOARD_ACTIVATE 0xF4
#define KEYBOARD_DEACTIVATE 0xF5
#define SET_LEDS 0xED

enum LED_MODES
{
    SCROLL_LOCK = 0x01,
    NUMBER_LOCK = 0x02,
    CAPS_LOCK = 0x04
};

void set_LEDs(uint8_t LEDs);
void init_keyboard(void);

#endif