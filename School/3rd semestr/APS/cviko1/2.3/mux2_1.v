module mux2_1(input a, b, select, output y);
	assign y = (a & ~select) | (b & select);
endmodule
