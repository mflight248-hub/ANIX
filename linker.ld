/* 1. Define the output binary format and architecture */
OUTPUT_FORMAT("elf32-i386")
OUTPUT_ARCH(i386)

/* 2. Define the execution entry point (the label of your first assembly instruction) */
ENTRY(_start)

SECTIONS
{
    /* 3. Begin assigning memory at 1MB. 
          This is standard practice for custom kernels to avoid BIOS/MMIO memory holes. */
    . = 0x00100000;

    /* 4. The Text Section: Contains your executable code */
    .text : ALIGN(4K)
    {
        /* CRITICAL: Force the Multiboot header to the absolute front of the binary,
           otherwise GRUB/bootloaders won't recognize it as a bootable kernel. */
        KEEP(*(.multiboot))
        
        *(.text)
    }

    /* 5. The Read-Only Data Section: Contains constants, strings, etc. */
    .rodata : ALIGN(4K)
    {
        *(.rodata)
    }

    /* 6. The Data Section: Contains initialized global variables */
    .data : ALIGN(4K)
    {
        *(.data)
    }

    /* 7. The BSS Section: Contains uninitialized global variables and the kernel stack */
    .bss : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }

    /* 8. Provide a visual anchor mark for the end of the kernel in memory */
    _kernel_end = .;
}
