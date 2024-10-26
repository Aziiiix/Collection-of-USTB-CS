module top_module (
    input clk,
    input reset,
    input enable,
    output reg [3:0] Q
);

always @(posedge clk) begin
    if(reset)
    Q<=4'b1;
    if(enable)begin
        if(Q<12)
        Q<=Q+1'b1;
        else
        Q<=4'b1;
    end
end


endmodule