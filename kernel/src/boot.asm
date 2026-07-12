/*
 * bip - Bip Is Perfect
 * Copyright (C) 2026  obrigani team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation version 3 of the License
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


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

