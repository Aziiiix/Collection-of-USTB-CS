module top_module(in1,in2,in3,out);

input in1,in2,in3;
output out;
wire in1,in2,in3,out,stat;

assign stat=((~in1)&(~in2))|(in1&in2);
assign out=(stat&(~in3))|((~stat)&in3);

endmodule