.section .text
.global _reloadSegments
.type _reloadSegments, @function

_reloadSegments:
    ljmp $0x08, $.reload_CS
.reload_CS:

    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss
    ret