//clkDiv.v
//CODE BY AZIIII

`timescale 1ns / 1ps

module clkDiv(
     input clk100mhz,//100Mhz的时钟频率使FPGA的系统时钟
     output clk190hz,//分频得到的190hz
     output clk3hz//分频得到的3hz
     );
     
     reg [25:0]count=0;//定义一个计数器
     assign clk190hz=count[18];//根据计数器的第19位的变化产生新的时钟
     assign clk3hz=count[25];//根据计数器的第26位的变化产生新的时钟
     always@(posedge clk100mhz)
         count<=count+1;
         
endmodule