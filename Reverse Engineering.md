# Basic computer architecture:
BRIDGE
|---memory bus----MEMORY
|----system bus----CPU
|----I/O bus---peripherals
- memory - stores data
- bridges - coordinates communication between buses
- buses - transfer info 
- periferals 
- CPU (Central Processing Unit)
	- processes information
	- ALU (Arithmetic Logic Unit) - does math
	- registers - stores data; register size ~ 1 work; named > addresses
	- control unit - executes code

# History
- Intel 8080 - 8-bit introduced in 1974
- Intel 8086 - 16-bit, 1978
- Intel 80386 - 32-bit, 1985
- Intel Prescott, AMD Opteron, Athlon 64 - 64-bit, 2003/4
- backwards compatibility - every generation adds feature, but never break or remove

# Assembly
= shorthand, more legible version of machine code
- e.g.. "sub" (subtract) ~ 0x83, "add" (add) ~ 0x81
- no standard syntax
	- in world of x86 syntax 2 main branches - AT&T (used by GCC) and Intel (used by Intel) → we will be using Intel
- [[x86]]

# Debugging
- breakpoints
	- software
		- set on assembly instructions
		- unlimited number
		- default
	- hardware
		- set on assembly instruction or memory access
		- limited number
- segmentation fault
	- CPU is attempting to read/write from a memory location that cannot be accessed (doesn't exist or insufficient permission)
	- GDB will tell us if it encounters it
- [[GDB]]
- [[objdump]]