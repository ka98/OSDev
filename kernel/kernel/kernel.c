#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gtd.h>

void kernel_main(void) {
	initialiceGTD();
	terminal_initialize();
	printf("Hello, kernel World!\n");
}
