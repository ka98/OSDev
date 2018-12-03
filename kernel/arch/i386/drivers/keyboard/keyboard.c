
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <kernel/tty.h>

#include "../io/io.h"
#include "keyboard.h"

void send_command(uint8_t command)
{
    //Waiting until Keyboard is ready, and commandbuffer is empty
    while ((inb(KBC_STATE_COMMAND_PORT) & 0x2))
    {
    }
    outb(KBC_IO_BUFFER_PORT, command);
}

void set_LEDs(uint8_t LEDs)
{
    send_command(SET_LEDS);
    send_command(LEDs);
}

void init_keyboard(void)
{
    //emptying keyboard buffer
    while (inb(KBC_STATE_COMMAND_PORT) & 0x1)
    {
        inb(KBC_IO_BUFFER_PORT);
    }

    // activate keyboard
    send_command(KEYBOARD_ACTIVATE);
}
