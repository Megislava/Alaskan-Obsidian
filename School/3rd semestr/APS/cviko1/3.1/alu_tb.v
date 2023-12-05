module test();
	reg [31:0]SrcA, SrcB;
	reg [1:0]ALUControl;
	wire Zero;
	wire [31:0]ALUResult;
	
	alu circuit(SrcA, SrcB, ALUControl, Zero, ALUResult);
	
	initial begin
		$dumpfile("test");
    		$dumpvars;
    		SrcA = 10;
    		SrcB = 5;
    		ALUControl = 0;
    		#10;
    		SrcA = 15;
    		SrcB = 8;
    		ALUControl = 1;
    		#10;
    		SrcA = 2;
    		SrcB = 3;
    		ALUControl = 2;
    		#10 $finish;
    	end
    	
endmodule
