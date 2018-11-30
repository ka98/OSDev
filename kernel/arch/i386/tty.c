#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <kernel/keyboardHandler.h>

#include <kernel/tty.h>
#include <kernel/io.h>

#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

void terminal_initialize(void) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_update_cursor()
{
	uint16_t pos = terminal_row * VGA_WIDTH + terminal_column;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}

static inline uint16_t terminal_getCCharAt(size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	return terminal_buffer[index];
}

static inline uint8_t terminal_getCharAt(size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	return terminal_buffer[index];
}

void terminal_putCCharAt(uint16_t colorChar, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = colorChar;
}

void terminal_putCharAt(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void scroll()
{
	for(size_t y = 0;y < VGA_HEIGHT-1;y++)
	{
		for(size_t x = 0;x < VGA_WIDTH;x++)
		{
			terminal_putCCharAt(terminal_getCCharAt(x, (y+1)), x, y);
		}
	}
}

void terminal_putchar(char c) {
	unsigned char uc = c;
	if (c == '\n') { //listen for newline character
		terminal_row++;
		terminal_column = 0;
	}
	
	else {

		terminal_putCharAt(c, terminal_color, terminal_column, terminal_row); 
			
		if (++terminal_column == VGA_WIDTH) {
			terminal_column = 0;
			terminal_row++;
		}
	}

	if(terminal_row == VGA_HEIGHT)
	{
		scroll();
	}
}

void terminal_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
		terminal_update_cursor();
}

void terminal_writestring(const char* data) {
	terminal_write(data, strlen(data));
}

void terminal_backspace(){
	if(terminal_row == 0 && terminal_column == 0)
	{
		return;
	} 
	else if (terminal_column == 0)
	{
		terminal_row--;
		terminal_column = VGA_WIDTH - 1;
		terminal_putCharAt(NUL, terminal_color, terminal_column, terminal_row);
	}
	else
	{
		terminal_column--;
		terminal_putCharAt(NUL, terminal_color, terminal_column, terminal_row);
	}
	terminal_update_cursor();
}

void terminal_delete() 
{
	terminal_putCharAt(NUL, terminal_color, terminal_column, terminal_row);
}
void terminal_cursor_up()
{
	if(terminal_row != 0)
	{
		terminal_row--;
	}
	terminal_update_cursor();
}
void terminal_cursor_down()
{
	if(terminal_row < VGA_HEIGHT-1)
	{
		terminal_row++;
	}
	terminal_update_cursor();
}
void terminal_cursor_left()
{
	if(terminal_column == 0 && terminal_row == 0)
	{
		return;
	}
	else if (terminal_column == 0)
	{
		terminal_row--;
		terminal_column = VGA_WIDTH - 1;
	}
	else
	{
		terminal_column--;
	}
	terminal_update_cursor();
}
void terminal_cursor_right()
{
	if(terminal_column == VGA_WIDTH -1 && terminal_row == VGA_HEIGHT -1 )
	{
		return;
	}
	else if (terminal_column == VGA_WIDTH)
	{
		terminal_row++;
		terminal_column = 0;
	}
	else
	{
		terminal_column++;
	}
	terminal_update_cursor();
}