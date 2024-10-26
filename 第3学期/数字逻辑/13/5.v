module top_module (
    input clk,
    input reset,
    input shift_ena,
    input count_ena,
    input data,
    output reg [3:0] q);

always @(posedge clk) begin
    if(reset)
    q<=4'b0;
    else begin
        if(count_ena)
        q<=q-1'b1;
        if(shift_ena)
        q<={q[2:0],data};
    end
end

endmodule