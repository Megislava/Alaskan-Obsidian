module inst_mem (
	input  [5:0] address,
	output [31:0] rd);

	reg [31:0] RAM[63:0];
	initial begin
		$readmemh ("primeHexa.hex",RAM,0,25);
	end
	assign rd=RAM[address]; // word aligned
endmodule