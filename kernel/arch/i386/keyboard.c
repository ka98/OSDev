
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <kernel/tty.h>

#include <kernel/io.h>
#include <kernel/keyboard.h>

void sendCommand(uint8_t command)
{
    //Waiting until Keyboard is ready, and commandbuffer is empty
    while ((inb(KBC_STATE_COMMAND_PORT) & 0x2)) {}
    outb(KBC_IO_BUFFER_PORT, command);
}

void setLEDs(uint8_t LEDs)
{
    sendCommand(SET_LEDS);
    sendCommand(LEDs);
}

void init_keyboard(void)
{
    //emptying keyboard buffer
    while (inb(KBC_STATE_COMMAND_PORT) & 0x1){
        inb(KBC_IO_BUFFER_PORT);
    }

    // activate keyboard
    sendCommand(KEYBOARD_ACTIVATE);
}
