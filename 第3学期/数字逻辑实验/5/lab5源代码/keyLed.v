//keyLed.v
//CODE BY AZIIII

`timescale 1ns / 1ps

module keyLed (
    input clk,
    input in_key,
    output out_key
);

reg [25:0] count_high=0;//高电平计数
reg [25:0] count_low=0;//低电平计数
reg reg_key;
parameter SAMPLE_TIME = 500000;//延时时间5ms

always @(posedge clk) begin
    if(in_key==1'b1)
    count_high<=count_high+1;
    else
    count_high<=0;
end

always @(posedge clk) begin
    if(in_key==1'b0)
    count_low<=count_low+1;
    else
    count_low<=0;
end

always@(posedge clk)begin
    if(count_high==SAMPLE_TIME)
    reg_key<=1;//输出1
    else if(count_low==SAMPLE_TIME)
    reg_key<=0;//输出0
    end

assign out_key=reg_key;
    
endmodule