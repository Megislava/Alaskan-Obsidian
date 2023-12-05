main:
    lw s0, 4(zero)     # s0 0x00000004
    lw s1, 8(zero)     # s1 0x00000008
    addi s2, zero, 0   # s2 = index v poli

loop_array:
    beq s2, s0, exit # stejne == konec pole -> end
    lw a0, 0(s1)    # a0 check for prime
    jal ra, prime    # ra return from prime
    sw a1, 0(s1)    # a1 save result to array
    addi s1, s1, 4   # move to next number
    addi s2, s2, 1   # s2++
    beq zero, zero, loop_array     # start again

exit:
    beq zero, zero, exit	
	
prime:
    addi t0, zero, 2      # t0 = 2
    addi a1, zero, 1
    
    addi t1, zero, 1 
    beq a0, t1, not_prime # 1 is not prime
    beq a0, zero, not_prime # 0 nebo 1
    beq a0, t0, is_prime  # 2 -> prime

loop:
    beq t0, a0, is_prime 
    rem t2, a0, t0       # t2 = a0 % t0 
    beq t2, zero, not_prime # zbytek 0 -> not prime
    addi t0, t0, 1       # t0 ++
    beq zero, zero, loop     # jump to loop

is_prime:
    addi a1, zero, 1      # init 1
    jalr zero, ra, 0

not_prime:
    addi a1, zero, 0      # init 0
    jalr zero, ra, 0
