module top_module(a,b,c,d,out,out_n);

input a,b,c,d;
output out,out_n;
wire w1,w2;

assign w1=a&b;
assign w2=c&d;
assign out=w1|w2;
assign out_n=~(w1|w2);

endmodule