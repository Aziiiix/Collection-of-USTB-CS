//clkDiv.v
//CODE BY AZIIII

`timescale 1ns / 1ps

module clkDiv(
input clk100mhz,
output clk190hz
    );
    reg[26:0] count=0;
    assign clk190hz=count[18];//取第19位信号
    always@(posedge clk100mhz)
    count<=count+1;
endmodule