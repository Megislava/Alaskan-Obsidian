module gprSet(
    input clk,
    input [19:15] a1,
    input [24:20] a2,
    input [11:7] a3,
    input [31:0]ReadData, // res
    input RegWrite,
    output [31:0] rs1,
    output [31:0] rs2);

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