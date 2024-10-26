//clkDiv.v
//CODE BY AZIIII

`timescale 1ns / 1ps

module clkDiv(
input clk100mhz,
output clk190hz
    );
    reg[26:0] count=0;
    assign clk190hz=count[18];
    always@(posedge clk100mhz)
    count<=count+1;
endmodule