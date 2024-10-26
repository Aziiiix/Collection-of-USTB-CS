module top_module(in1,in2,out);

input in1,in2;
output out;
wire in1,in2,out;

assign out=in1&(~in2);

endmodule