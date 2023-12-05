module composed_circuit(input a, b, input [1:0] select,
                 output y);

  wire w1,w2;

  mux2_1 levy_mux(a,b,select[1],w1);
  mux2_1 pravy_mux(w1,w2,select[0],y);
  assign w2 = a & b;
endmodule

