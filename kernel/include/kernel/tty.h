#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>

void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void terminal_backspace();
void terminal_cursor_up();
void terminal_cursor_down();
void terminal_cursor_left();
void terminal_cursor_right();
void terminal_delete();

#endif
