//check.v
//CODE BY AZIIII

module check (
    input clk,

    input [3:0]weight,
    input [3:0]per,

    output reg [7:0]light
);

always @(posedge clk) begin
    if(weight[3])
    light[0]<=1;
    else light[0]<=0;
    if(weight[2])
    light[1]<=1;
    else light[1]<=0;
    if(weight[1])
    light[2]<=1;
    else light[2]<=0;
    if(weight[0])
    light[3]<=1;
    else light[3]<=0;
    if(per[3])
    light[4]<=1;
    else light[4]<=0;
    if(per[2])
    light[5]<=1;
    else light[5]<=0;
    if(per[1])
    light[6]<=1;
    else light[6]<=0;
    if(per[0])
    light[7]<=1;
    else light[7]<=0;
end
    
endmodule