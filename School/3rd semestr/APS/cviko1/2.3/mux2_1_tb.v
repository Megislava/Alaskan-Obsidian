module test();
  reg a, b, select;
  wire y;

  mux2_1 my_circuit_XYZ(a, b, select, y); // <- zde je instance obvodu, který simulujeme.

  initial begin
    $dumpfile("test");
    $dumpvars;
    a=0;
    b=1;
    select=0;
    #10;
    a=1;
    #10;
    a=0;
    #10;
    select=1;
    #10 $finish;
  end

endmodule
