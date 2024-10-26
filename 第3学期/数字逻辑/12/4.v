module top_module (
    input [3:0] in,
    output reg [1:0] pos
);
always @(*) begin

    pos=0;
    if(in[3])pos=3;
    if(in[2])pos=2;
    if(in[1])pos=1;
    if(in[0])pos=0;

end

endmodule