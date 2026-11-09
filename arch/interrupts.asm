[bits 32]                         

; --- External Symbols ---
extern keyboard_intr_handler      ; FIXED: Matches your C driver function name!

; --- Global Symbols ---
global keyboard_isr_asm_stub      ; Export this stub so your C IDT initialization code can see it

section .text

; =============================================================================
; KEYBOARD INTERRUPT SERVICE ROUTINE STUB (IRQ 1)
; =============================================================================
keyboard_isr_asm_stub:
    pusha                         ; Save all general-purpose registers (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI)

    ; Save segment registers to preserve context stability
    push ds
    push es
    push fs
    push gs

    ; Load kernel data segment descriptor (typically 0x10 for flat mode)
    mov ax, 0x10
    mov ds, ax
    mov es, ax

    ; Call your header-only C driver logic
    call keyboard_intr_handler    ; FIXED: Jumps to the exact C handler!

    ; Restore segment registers
    pop gs
    pop fs
    pop es
    pop ds

    popa                          ; Restore all general-purpose registers
    iretd                         ; FIXED: 32-bit Interrupt Return (pops EIP, CS, and EFLAGS)
