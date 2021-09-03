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
		- in world of x86 syntax 2 main branches - AT&T (used by GCC) and Intel (used by Intel) -> we will be using Intel
4. x86
	- data representation:
		-   least significant bit (LSB) - the one on far right
		-   most significant bit (MSB) - the one far on left
		-   little-endian - LSB is stored first
		-   big-endian - MSB is sroted first
	-   x86 is a little-endian
	-   registers:
		1. GPRs (general purpose registers)
			- eax - accumulator register - to accumulate results of arithmatic operations
			- ebx - the base register - to store the base of an address
			- ecx - the counter register - to count, usually used in loops
			- edx - the data register - store and work w/ data 
			- esi - source index register - to store the index into a source array
			- edi - destination index register - to store the index of a destination array 
			- ebp - base pointer - stores the address of the case of the stack frame
			- esp - stack pointer - addresses the top of the stack frame
		2. SPRs (special purpose registers)
			- eip - instruction pointer - stored s address of the next instruction to execute
			- eflags - stored the flags about system state and info about the resilts of previously executed instructions
			- cannot be access directly - `mov eip,1` <- does not assemble
		- registers ending with 'x' can be access in parts:
			- *eax* ~ 32-bit register; *ax* ~ lower 16-bit of erx; *ah* ~ higher/top 8-bits of rx; *al* ~ lower 8-bits of rx 
			[[17.PNG]]
		- in x86_64 (64-bit) the register name starts with 'r' (*eax*)
	- accessing memory
		- with `[]` notation, eg. `[0x231435]` access the value stored at memory address 0x231435; `[eax]` access the value stored at the memory pointed to by eax
		- different sizes of memory can be accessed
			- `byte [100]` (single byte on address 100), `word[ebx]` (word ~ 2 bytes pointed to by ebx), `dword[ax]` (doubleword ~ 4bytes pointed to by ax)
		- direct and indirect addressing
			- direct - directly address some constant value address - by number of the address, offset or label; like global variable
			- indirect - uses a register to indicate the address, like pointers, the address "name" is not know before compilation, only 16- and 32-bit GPR can be used for indirect addressing (no 8-bit/SPR)
		- base + displacement addressing
			- used often for array work
			- uses register and an absolute displacement
			- like local variable
			- eg. `[ ebx + 0x100 ]`
		- indexed addressing
			- uses an index register, scale factor and a displacement for an address
			- for arrays, structures etc where you know the base and the max size/offset
			- the index must be 1, 2, 4, or 8
			- eg. `[ eax * 2 + 0x100]`
		- based-indexed addressing
			- uses a base register, index register, scale factor and a displacement for the address
			- like structure
			- the index must be 1, 2, 4, or 8
			- eg. `[ ebx + edi * 4 + 0x1000 ]`
		- [[18.PNG]]
	- instructions
		- generally x86 instruction can access multiple of registers at once but:
			- only one memory location at once (`[0x12436666]`)
		1. Arithmetic
			1. add, sub
				- addition, subtration
				- destication can be register/memory
				- value: register/memory/immediate
				- operands must have the same size (`add eax, bx` is invalid)
				- `add destination, value`
				- `sub destination, value`
				- `add eax, ebx` - add ebx to eax and store in eax
				- `sub ecx, [ 100 ]` - subtract the 32-bit (ecx is 32-bit) value at address `[ 100 ]` from ecx and store in ecx
				- `add dword [ edx ], 100` - add 100 to 32-bit value pointed to by edx and store there, 
			3. mul
				- multiply eax by operand, stores the result in edx:eax
				- `mul [ memory ]` / `mul register`
				- ALWAYS uses eax register as source
				- ALWAYS stores as edx:eax
				- -> eax and edx are always modified 
				- `mul eax` - edx:eax = eax * eax (eax square)
				- `mul ebx` - edx:eax = eax * ebx
				- `mul dword [ 0x555 ]` - edx:eax = eax * (32-bit value at address 0x555)
				- `mul byte [ 0x123 ]` - edx:eax = eax * (8-bit value an address 0x123)
			4. div
				- divide edx:eax by operand, store quotient in eax and reminder in edx
				- `div [ memory ]` or `div register`
				- source and storage is alwaus same -> eax and edx are always modified
				- `div eax` - eax, edx = edx:eax / eax
				- `div ebx` - eax, edx = edx:eax / ebx
				- `div dword [ 0x555 ]` - eax, edx = edx:eax / (32-bit value at address 0x555)
				- `div byte [ 0x123 ]` - eax, edx = edx:eax / (8-bit value at address 0x123)
			5. inc, dec
				- increment/decrement by 1
				- `inc eax` - increment the eax register by 1
				- `dec dx` - decrease dx register by 1
				- `inc word [ ecx ]` - increment the 16-bit value pointed to by ecx
				- `dec dword [ 0x11223344 ]` - decrease the 32-bit value at 0x11223344 by 1
		2. Bit manipulation
			1. and
			2. or
			3. xor
			4. not
		3. Stack
			1. call
			2. return
			3. push
			4. pop
		4. Data movement
			1. mov
				- moves (it's actually copy) data from one location to another
				- `mov destination, source`
				- [[19.PNG]]
		5. Execution flow
			1. jmp
			2. Conditional jumps
		6. Comparison
			1. test
			2. cmp
		7. Other
			1. lea
			2. nop