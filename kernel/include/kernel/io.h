#ifndef _KERNEL_IO_H
#define _KERNEL_IO_H

#include <stddef.h>

void outb(uint16_t port, uint8_t data);
uint8_t inb(uint16_t port);

#endif