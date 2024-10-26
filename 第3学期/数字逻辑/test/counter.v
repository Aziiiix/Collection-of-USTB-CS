module counter (
    out,clk,rst
);

output reg [3:0] out;
input clk,rst;
wire clk,rst;

always @(negedge rst or posedge clk) begin
    if(!rst)
    out<=0;
    else
    out<=out+1;
end
    
endmodule