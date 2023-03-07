1.  basic computer architecture:
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
		- control unit - execudes code
2. history
	- Intel 8080 - 8-bit introduced in 1974
	- Intel 8086 - 16-bit, 1978
	- Intel 80386 - 32-bit, 1985
	- Intel Prescott, AMD Opteron, Athlon 64 - 64-bit, 2003/4
	- backwards compatibility - every generation adds feature, but never break or remove
3. ASSEMBLY
	= shorthand, more legible version of machine code
	- eg. "sub" (subtract) ~ 0x83, "add" (add) ~ 0x81
	- no standart syntax
		- in world of x86 syntax 2 main branches - AT&T (used by GCC) and Intel (used by Intel) → we will be using Intel
	- [[x86]]
4. Debugging
	- [[GDB]]
	- [[objdump]]