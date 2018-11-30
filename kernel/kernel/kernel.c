#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gtd.h>
#include <kernel/idt.h>
#include <kernel/keyboard.h>
#include <kernel/keyboardHandler.h>

void kernel_main(void) {
	keyboardHandlerInit();
	init_keyboard();
	asm("sti");
	terminal_initialize();
	printf("Hello, kernel World!\n");
	while(1);
}
