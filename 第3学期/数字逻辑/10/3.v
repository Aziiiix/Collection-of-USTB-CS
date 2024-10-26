module top_module(a,b,out);

input a;
input b; 
output out;

assign out=~(a|b);

endmodule