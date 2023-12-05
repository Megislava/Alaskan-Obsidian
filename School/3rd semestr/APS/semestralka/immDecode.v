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