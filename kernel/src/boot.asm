// Constants for the Multiboot header
.set ALIGN,    1<<0             // Align loaded modules on page boundaries
.set MEMINFO,  1<<1             // Provide the memory map
.set FLAGS,    ALIGN | MEMINFO  // Pass those values to the 'flag' multiboot field
.set MAGIC,    0x1BADB002       // Magic number that is required by the protocol
.set CHECKSUM, -(MAGIC + FLAGS)

// The Multiboot section
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

// Stack pointer
.section .bss
.align 16
stack_botton:
.skip 16384 // 16 KiB
stack_top:

.section .text
.global _start
.type _start, @function
_start:
  // Setting up the stack
  mov $stack_top, %esp

  // Some other bs will be loaded here

  // High-level kernel
  call kmain

  cli // Disable interrupts
1:hlt // Halt until an interrupt
  jmp 1b // Jump to halt just in case

.size _start, . - _start

