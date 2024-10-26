module top_module (
    input clk,
    input [7:0] in,
    output reg [7:0] anyedge
);

reg [7:0] temp;

initial begin
    temp=0;
end

always @(posedge clk) begin
    temp<=in;
    anyedge<=temp^in;
end

endmodule