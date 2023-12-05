module alu(input [31:0]SrcA, SrcB, input [1:0]ALUControl, output reg Zero, output reg [31:0]ALUResult);
	always @(*)
		case(ALUControl)
			0: ALUResult = SrcA + SrcB;
			1: ALUResult = SrcA - SrcB;
			2: ALUResult = SrcA ^ SrcB;
			default: ALUResult = 0;
		endcase
	always @(*)
		if(ALUResult == 0) Zero = 1;
		else Zero = 0;
endmodule
