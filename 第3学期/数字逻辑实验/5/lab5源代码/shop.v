//shop.v
//CODE BY AZIIII

`timescale 1ns / 1ps

module shop (
    input clk,
    input cal,
    input reset,

    input [3:0]weight,
    input [3:0]per,

    output reg [7:0]price,
    output reg [7:0]times=0,
    output reg [15:0]sum=0,

    output reg state_cal,
    output reg state_reset=0
);

reg [3:0]station_weight;
reg [3:0]station_per;

reg temp=1'b0;

always @(posedge clk) begin
    if(state_reset==0)begin
        price<=weight*per;
        if(state_cal==1 && temp==0)begin
            sum<=sum+price;
            times<=times+1;
        end
        temp<=state_cal;
    end

    else begin
        sum<=0;
        times<=0;
        price<=0;
    end

    station_weight<=weight;
    station_per<=per;

end

    
always @(posedge clk or posedge reset) begin
    if(reset)
    state_reset<=1;

    else if ((weight!=station_weight)||(per!=station_per)) begin
        state_reset<=0;
    end
end

always @(posedge clk) begin
    if(cal)
    state_cal<=1;
    else if ((weight!=station_weight)||(per!=station_per)) begin
        state_cal<=0;
    end
end
endmodule