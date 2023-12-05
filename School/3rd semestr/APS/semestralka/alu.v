module alu(
	input [31:0]SrcA, SrcB, 
	input [3:0]ALUControl, 
	output Zero, 
	output [31:0]ALUOutput);
	always @(*)
		case(ALUControl)
			0: ALUOutput = SrcA + SrcB; // add
			//1: ALUOutput = SrcA << SrcB; // sll
			2: ALUOutput = ($signed(SrcA) < $signed(SrcB)); // slt
			3: ALUOutput = SrcA - SrcB; // sub
			4: ALUOutput = SrcA / SrcB; // div
			//5: ALUOutput = SrcA >> SrcB; // srl + sra (unsigned vs signed)
			6: ALUOutput = SrcA % SrcB; // rem
			7: ALUOutput = SrcA & SrcB; // and
			8: ALUOutput = SrcB;
			//9: ALUOut = $signed(SrcA) >>> SrcB;
			default: ALUOutput = 0;
		endcase
	always @(*)
		if(ALUOutput == 0) Zero = 1;
		else Zero = 0;
endmodule
