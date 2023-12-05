addi x1,x0,0  # Pocatecni nastaveni hodnoty registru

# Sem dopiste Vas kod:
addi x2, x0, 1
addi x3, x0, 6

loop:
	add x1, x1, x2 # add x1 and x2
	addi x2, x2, 1 # x2++
	bne x2, x3, loop # go to loop until x2 == x3


inf_loop:
beq x0,x0,inf_loop