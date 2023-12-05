module controlUnit(
	input [31:0]instruction, 
	output reg BranchBeq, BranchBlt, BranchJal, BranchJalr,
    output reg RegWrite, MemToReg, MemWrite,
    output reg ALUControl, ALUSrc;
	output reg immControl
	);

	always @(*) begin
		casez({instruction[6:0], instruction[14:12], instruction[31:25]})
            // for instruction 0110011 => goes to ALU
            // operations: add, and, sub, slt, div, rem (, sll, srl, sra)
			'b0110011_000_0000000: begin  // add
                BranchBeq = 0;
                BranchBlt = 0;
                BranchJal = 0;
                BranchJalr = 0;
                MemToReg = 0;
                MemWrite = 0;
                ALUControl = 0;
                ALUSrc = 0;
                immControl = 0;
				RegWrite = 1;
                end
            'b0010011_000_???????: begin  // addi
                BranchBeq = 0;
                BranchBlt = 0;
                BranchJal = 0;
                BranchJalr = 0;
                MemToReg = 0;
                MemWrite = 0;
				RegWrite = 1;
                ALUControl = 0;
                ALUSrc = 1;
                immControl = 0;
			    end
            'b0110011_111_0000000: begin  // and
                BranchBeq = 0;
                BranchBlt = 0;
                BranchJal = 0;
                BranchJalr = 0;
                MemToReg = 0;
                MemWrite = 0;
                ALUControl = 7;
                ALUSrc = 0;
                immControl = 0;
				RegWrite = 1;
                end
            'b0110011_000_0100000: begin  // sub
                BranchBeq = 0;
                BranchBlt = 0;
                BranchJal = 0;
                BranchJalr = 0;
                MemToReg = 0;
                MemWrite = 0;
                ALUControl = 3;
                ALUSrc = 0;
                immControl = 0;
				RegWrite = 1;
                end
            'b0110011_010_0000000: begin  // slt
                BranchBeq = 0;
                BranchBlt = 0;
                BranchJal = 0;
                BranchJalr = 0;
                MemToReg = 0;
                MemWrite = 0;
                ALUControl = 2;
                ALUSrc = 0;
                immControl = 0;
				RegWrite = 1;
                end
            'b0110011_100_0000001: begin  // div
                BranchBeq = 0;
                BranchBlt = 0;
                BranchJal = 0;
                BranchJalr = 0;
                MemToReg = 0;
                MemWrite = 0;
                ALUControl = 4;
                ALUSrc = 0;
                immControl = 0;
				RegWrite = 1;
                end
            'b0110011_110_0000001: begin  // rem
                BranchBeq = 0;
                BranchBlt = 0;
                BranchJal = 0;
                BranchJalr = 0;
                MemToReg = 0;
                MemWrite = 0;
                ALUControl = 6;
                ALUSrc = 0;
                immControl = 0;
				RegWrite = 1;
                end
            'b1100011_000_???????: begin  // beq
				BranchJal = 0;
                BranchBlt = 0;
                BranchJalr = 0;
                RegWrite = 0;
                MemToReg = 0;
                MemWrite = 0;
                ALUControl = 3;
                ALUSrc = 0;
                BranchBeq = 1;
                immControl = 2;
			    end
            'b1100011_100_???????: begin  // blt
				BranchJal = 0;
                BranchJalr = 0;
                RegWrite = 0;
                MemToReg = 0;
                MemWrite = 0;
                ALUControl = 2;
                ALUSrc = 0;
                BranchBeq = 1;
                BranchBlt = 1;
                immControl = 2;
			    end
            'b0000011_010_???????: begin  // lw
				BranchBeq = 0;
                BranchBlt = 0;
                BranchJal = 0;
                BranchJalr = 0;
                MemWrite = 0;
                ALUControl = 0;
                RegWrite = 1;
                MemToReg = 1;
                ALUSrc = 1;
                immControl = 0;
			    end
            'b0100011_010_???????: begin  // sw
                BranchBeq = 0;
                BranchBlt = 0;
                BranchJal = 0;
                BranchJalr = 0;
                RegWrite = 0;
                MemToReg = 1;
                ALUControl = 0; 
				MemWrite = 1;
                ALUSrc = 1;
                immControl = 1;
			    end
            'b0110111_???_???????: begin  // lui
				BranchBeq = 0;
                BranchBlt = 0;
                BranchJal = 0;
                BranchJalr = 0;
                MemToReg = 0;
				MemWrite = 0;
                ALUSrc = 1;
                RegWrite = 1;
                ALUControl = 8;
                immControl = 3;
			    end
            'b1101111_???_???????: begin  // jal
				BranchBeq = 0;                
                BranchBlt = 0;
                BranchJalr = 0;
                MemToReg = 0;
                MemWrite = 0;
                ALUControl = 0;
                ALUSrc = 0;
                BranchJal = 1;
                RegWrite = 1;
                immControl = 4;
			    end
            'b1100111_000_???????: begin  // jalr
				BranchJalr = 1;
                RegWrite = 1;
                ALUSrc = 1;
                BranchBeq = 0;                
                BranchBlt = 0;
                BranchJal = 0;
                MemToReg = 0;
                MemWrite = 0;
                ALUControl = 0;
                immControl = 0;
			    end            
            'b0010111_???_???????: begin  // auipc
                end
            'b0110011_001_0000000: begin  // sll
                end
            'b0110011_101_0000000: begin  // srl
                end
            'b0110011_101_0100000: begin  // sra
                end

			default: begin
				BranchBeq = 0;                
                BranchBlt = 0;
                BranchJal = 0;
                BranchJalr = 0;
                RegWrite = 0;
                MemToReg = 0;
                MemWrite = 0;
                ALUControl = 0;
                ALUSrc = 0;
                immControl = 0;
			    end
			endcase
            end
endmodule   