//top.v
//CODE BY AZIIII

`timescale 1ns / 1ps

module top(
    input clk100mhz,
    input btm_cal,
    input btm_reset,

    input [3:0]weight,
    input [3:0]per,

    output [3:0]pos1,
    output [3:0]pos2,
    output [7:0]seg1,
    output [7:0]seg2
);

    wire clk190hz;
    wire cal,reset;
    
    wire [7:0]price;
    wire [7:0]times;
    wire [15:0]sum;

    wire state_cal;
    wire state_reset;

clkDiv U1(clk100mhz,clk190hz);
keyLed U2(clk100mhz,btm_cal,cal);
keyLed U3(clk100mhz,btm_reset,reset);
shop U4(clk100mhz,cal,reset,weight,per,price,times,sum,state_cal,state_reset);
segMsg U5(clk190hz,state_cal,state_reset,weight,per,price,times,sum,pos1,seg1,pos2,seg2);
endmodule
