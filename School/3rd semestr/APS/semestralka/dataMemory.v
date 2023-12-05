module data_mem (
	input clk, we,
	input  [31:0] address, wd,
	output [31:0] rd);

	reg [31:0] RAM[63:0];

	initial begin
		$readmemh ("data.hex",RAM,0,10);
	end

	assign rd=RAM[address[31:2]]; // word aligned

	always @ (posedge clk)
		if (we)
			RAM[address[31:2]]<=wd;
endmodule