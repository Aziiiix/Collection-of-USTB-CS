module top_module (

input [7:0] a, b, c, d,
output [7:0] min);

assign min=((a<b?a:b)<c?(a<b?a:b):c)<d?((a<b?a:b)<c?(a<b?a:b):c):d;

endmodule