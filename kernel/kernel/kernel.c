#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gtd.h>
#include <kernel/idt.h>

void kernel_main(void) {
	initialiceGTD();
	idt_init();
	terminal_initialize();
	printf("Hello, kernel World!\n");
	while(1);
}
