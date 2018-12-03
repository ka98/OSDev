# Declare constants for the multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Reserve a stack for the initial thread.
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# The kernel entry point.
.section .text
.extern initialice_gdt
.extern idt_init
.extern keyboard_handler_init
.extern init_keyboard

.global _start
.type _start, @function
_start:
	# Setting up GTD
	call initialice_gdt

	# setting up Stack
	movl $stack_top, %esp

	# Setting up IDT
	call idt_init

	# Setting up the key-function-table for the keyboard-irq-Handler
	call keyboard_handler_init

	# Initializes the Keyboard via IO-Ports
	call init_keyboard

	# Call the global constructors.
	call _init

	# Enable hardweare interrupts
	sti

	# Transfer control to the main kernel.
	call kernel_main

	# Hang if kernel_main unexpectedly returns.
	cli
1:	hlt
	jmp 1b
.size _start, . - _start
