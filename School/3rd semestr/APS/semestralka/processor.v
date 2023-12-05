`default_nettype none
module processor( input         clk, reset,
                  output [31:0] PC,
                  input  [31:0] instruction,
                  output        WE,
                  output [31:0] address_to_mem,
                  output [31:0] data_to_mem,
                  input  [31:0] data_from_mem
                );
    wire [2:0]immControl;
    wire [3:0]ALUControl;
    // extra ridici signaly
    wire BranchOutcome, BranchJalx, BranchBeq, BranchBlt, BranchJalr, BranchJal, RegWrite, MemToReg, MemWrite, ALUSrc, Zero;
    // custom AND outcome
    wire andOutcome;
    // 32-bitove datove cesty
    wire [31:0] PCn, immOp, rs1, rs2, ALUOutput, SrcB, res, BranchTarget, PCPlus4, addResult, read, resFlag;

    mux3to1 muxToPCn(PCPlus4, BranchTarget, BranchOutcome, PCn);
    programCounter counter(clk, reset, PCn, PC);

    adder add4ToPC(4, PC, PCPlus4);

    controlUnit ctrlUnit(instruction, BranchBeq, BranchBlt, BranchJal, BranchJalr, RegWrite, MemToReg, MemWrite, ALUSrc, ALUControl, immControl);
    gprSet set(clk, instruction[19:15], instruction[24:20], instruction[11:7], res, RegWrite, rs1, rs2);
    immDecode decode(instruction[31:7], immControl, immOp);

    mux3to1 muxToSrcB(rs2, immOp, ALUSrc, SrcB);
    alu aluUnit(rs1, SrcB, ALUControl, Zero, ALUOutput);
    adder addImmOpToPC(immOp, PC, addResult);
    mux3to1 muxToBranchTarget(addResult, ALUOutput, BranchJalr, BranchTarget);

    mux3to1 muxToResFlag(ALUOutput, PCPlus4, BranchJalx, resFlag);

    mux3to1 muxToRes(resFlag, data_from_mem, MemToReg, res);

    logicalAnd branchAnd(BranchBeq, Zero, andOutcome);
    logicalOr branchOr(BranchJal, BranchJalr, BranchJalx);
    logicalOr branchOrCompete(BranchJalx, andOutcome, BranchOutcome);

    assign WE = MemWrite;
    assign address_to_mem = ALUOutput;
    assign data_to_mem = rs2;
    //assign data_from_mem = res;
endmodule

module adder(
    input [31:0]a,
    input [31:0]b,
    output [31:0]y);
  assign y = a + b;
endmodule

module alu(
	input [31:0]rs1, SrcB, 
	input [3:0]ALUControl, 
	output reg Zero, 
	output reg [31:0]ALUOutput);
	always @(*)
		case(ALUControl)
			0: ALUOutput = rs1 + SrcB; // add
			//1: ALUOutput = rs1 << SrcB; // sll
			2: ALUOutput = ($signed(rs1) < $signed(SrcB)); // slt
			3: ALUOutput = rs1 - SrcB; // sub
			4: ALUOutput = rs1 / SrcB; // div
			//5: ALUOutput = rs1 >> SrcB; // srl + sra (unsigned vs signed)
			6: ALUOutput = rs1 % SrcB; // rem
			7: ALUOutput = rs1 & SrcB; // and
			8: ALUOutput = SrcB;
			//9: ALUOut = $signed(rs1) >>> SrcB;
			default: ALUOutput = 0;
		endcase
	always @(*)
		if(ALUOutput == 0) Zero = 1;
		else Zero = 0;
endmodule

module controlUnit(
	input [31:0]instruction, 
	output reg BranchBeq, BranchBlt, BranchJal, BranchJalr,
    output reg RegWrite, MemToReg, MemWrite, ALUSrc,
    output reg [3:0]ALUControl,
	output reg [2:0]immControl
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

module programCounter(
    input clk,
    input reset,
    input [31:0]PCn,
    output reg [31:0]PC
    );
    always @(posedge clk) begin
        PC = reset ? 0 : PCn;
        end
endmodule

module gprSet(
    input clk,
    input [19:15] a1,
    input [24:20] a2,
    input [11:7] a3,
    input [31:0]ReadData, // res
    input RegWrite,
    output reg [31:0] rs1,
    output reg [31:0] rs2);

    reg [31:0] reg_file [31:0];

    always @(*) begin
        rs1 = a1 ? reg_file[a1] : 0;
        rs2 = a2 ? reg_file[a2] : 0;
        end
    
    always @(posedge clk) begin
        if (RegWrite) begin
            reg_file[a3] = ReadData;
            end
        end
    /*initial begin
        integer i;
        for(i = 0; i < 32; i = i + 1) begin
            reg_file[i] = 0;
            end
    end*/
endmodule

module immDecode(
    input [31:7]instr,
    input [2:0]immControl,
    output reg [31:0]immOp);

    always @(*) begin
        case(immControl)
            0: begin // imm[11:0] I-type
                immOp = {{21{instr[31]}}, instr[30:20]};
                end
            1: begin // imm[11:5] + imm[4:0] S-type
                immOp = {{21{instr[31]}}, instr[30:25], instr[11:7]};
                end
            2: begin // imm[12|10:5] + imm[4:1|11] B-type
                immOp = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
                end
            3: begin // imm[31:12] U-type
                immOp = {instr[31:12], 12'b0};
                end
            4: begin // imm[20|10:1|11|19:12] J-type
                immOp = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};
                end
            default:
                immOp = 32'b0;
        endcase
        end
endmodule

module logicalAnd(input a, b, output y);
	assign y = (a & b);
endmodule

module logicalOr(input a, b, output y);
	assign y = (a | b);
endmodule

module mux3to1(
    input [31:0]a,
    input [31:0]b,
    input select,
    output [31:0]y);
  assign y = (select == 0) ? a : b;
endmodule

`default_nettype wire