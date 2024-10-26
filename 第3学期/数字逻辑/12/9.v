module top_module (
    input clk,
    input w, R, E, L,
    output reg Q
);

initial begin
    Q=0;
end

wire temp;
assign temp=L?R:(E?w:Q);

always @(posedge clk) begin
    Q<=temp;
end

endmodule