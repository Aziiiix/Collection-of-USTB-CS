module top_module (
    input d,
    input ena,
    output reg q
);

initial begin
    q=0;
end

always @(*) begin
    if(ena)
    q<=d;
end
    
endmodule