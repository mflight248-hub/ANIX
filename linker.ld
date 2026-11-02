ENTRY(_start)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386)

SECTIONS
{
    /* GRUB loads the kernel into physical RAM starting at 1MB */
    . = 0x00100000;

    /* Executable code and Multiboot Header */
    .text : ALIGN(4K)
    {
        /* CRITICAL: The Multiboot header must be within the first 8KB */
        KEEP(*(.multiboot))
        *(.text.boot)
        *(.text*)
    }

    /* Read-only data (constants, strings) */
    .rodata : ALIGN(4K)
    {
        *(.rodata*)
    }

    /* Initialised writable data */
    .data : ALIGN(4K)
    {
        *(.data*)
    }

    /* Uninitialised data (Stack, Heap) */
    .bss : ALIGN(4K)
    {
        *(COMMON)
        *(.bss*)
    }

    /* Define a symbol for the end of the kernel memory image */
    _kernel_end = .;
}
