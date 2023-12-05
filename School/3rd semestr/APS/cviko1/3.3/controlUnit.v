module controlUnit(
	input [2:0]Opcode, 
	output reg ALUSrc, RegWrite, 
	output reg [1:0]ALUControl,
	output reg MemWrite, Branch
	);
	always @(*)
		case(Opcode)
			0: begin
				ALUSrc = 0;
				RegWrite = 1;
				ALUControl = 0;
				MemWrite = 0;
				Branch = 0;
			end
			1: begin
				ALUSrc = 1;
				RegWrite = 1;
				ALUControl = 0;
				MemWrite = 0;
				Branch = 0;
			end
			2: begin
				ALUSrc = 0;
				RegWrite = 1;
				ALUControl = 1;
				MemWrite = 0;
				Branch = 0;
			end
			3: begin
				ALUSrc = 1;
				RegWrite = 1;
				ALUControl = 0;
				MemWrite = 0;
				Branch = 0;
			end
			4: begin
				ALUSrc = 1;
				RegWrite = 0;
				ALUControl = 0;
				MemWrite = 1;
				Branch = 0;
			end
			5: begin
				ALUSrc = 0;
				RegWrite = 0;
				ALUControl = 1;
				MemWrite = 0;
				Branch = 1;
			end
			default: begin
				ALUSrc = 0;
				RegWrite = 0;
				ALUControl = 0;
				MemWrite = 0;
				Branch = 0;
			end
			endcase
endmodule