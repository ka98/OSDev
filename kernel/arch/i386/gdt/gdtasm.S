.section .text
.global reload_segments
.type reload_segments, @function

reload_segments:
    #Reload CS register containing code selector:
    ljmp $0x08, $.reload_CS #0x08 points at the new code selector
.reload_CS:
    #Reload data segment registers
    mov $0x10, %ax #0x10 points at the new data selector
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss
    ret