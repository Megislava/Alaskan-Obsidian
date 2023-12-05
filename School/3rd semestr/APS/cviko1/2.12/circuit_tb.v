module test();
  reg a, b, c;
  wire x, y;

  circuit circuit_XY(a, b, c, x, y); // <- zde je instance obvodu, který simulujeme.

  initial begin
    $dumpfile("test");
    $dumpvars;
    a=0;
    b=0;
    c=0;
    #160 $finish;
  end

  always #20 a = ~a;
  always #40 b = ~b;
  always #80 c = ~c;

  always @(x) #1 $display( "The value of x was changed. Time=%5d, x=%b. Inputs: a=%b, b=%b, c=%b.",$time, x,a,b,c);

endmodule
