module top_module(p1a, p1b, p1c, p1d, p1e, p1f,p2a, p2b, p2c, p2d,p1y,p2y);

input p1a, p1b, p1c, p1d, p1e, p1f,p2a, p2b, p2c, p2d;
output p1y,p2y;
wire p1a, p1b, p1c, p1d, p1e, p1f,p2a, p2b, p2c, p2d,p1y,p2y;

assign p1y=(p1a&p1b&p1c)|(p1f&p1e&p1d);
assign p2y=(p2a&p2b)|(p2c&p2d);

endmodule