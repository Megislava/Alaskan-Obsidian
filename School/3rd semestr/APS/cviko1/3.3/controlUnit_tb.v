module test();
  reg [2:0] Opcode;
  wire ALUSrc, RegWrite, MemWrite, Branch;
  wire [1:0] ALUControl;

  wire [5:0] Ctrls;

  assign Ctrls = {ALUSrc, RegWrite, ALUControl, MemWrite, Branch};

  controlUnit CU(Opcode, ALUSrc, RegWrite, ALUControl, MemWrite, Branch);

  initial begin
    $dumpfile("test");
    $dumpvars;
    Opcode = 0;
    #12 $display("Note: This testbench cannot test the control unit if implemened as a sequential circuit.");
    $finish;
  end

  always #2 Opcode = Opcode+1;

  always @(*) begin
    #1;
    casez({Opcode,Ctrls})
  'b 000_0_1_00_0_0: $display("add:  OK");
  'b 001_1_1_00_0_0: $display("addi: OK");
  'b 010_0_1_01_0_0: $display("sub:  OK");
  'b 011_1_1_00_0_0: $display("lw:   OK");
  'b 100_1_0_00_1_0: $display("sw:   OK");
  'b 101_0_0_01_0_1: $display("beq:  OK");
  'b 11?_?_?_??_?_?: $display("Unknown Opcode: not testing");
  default: $display("Control unit FAILED!!! Opcode: %b",Opcode);
    endcase
  end

endmodule