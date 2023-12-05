module programCounter(
    input clk,
    input reset,
    input [31:0]PCn,
    output [31:0]PC);
    always @(posedge clk) begin
        PC = reset ? 0 : PCn;
        end
endmodule