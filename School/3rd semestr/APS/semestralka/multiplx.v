module mux3to1(
    input [31:0]a,
    input [31:0]b,
    input select,
    output [31:0]y);
  assign y = (select == 0) ? a : b;
endmodule