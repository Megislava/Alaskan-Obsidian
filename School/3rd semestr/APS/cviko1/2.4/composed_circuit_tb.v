module composed_circuit_tb();
  reg a, b;
  reg [1:0] select;
  wire out;

  composed_circuit xxx(a,b,select,out);

  initial begin
    $dumpfile("test");
    $dumpvars;
    // left to students
    #10 $finish;
  end

endmodule
