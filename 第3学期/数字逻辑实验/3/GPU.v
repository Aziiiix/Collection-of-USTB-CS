//GPU.v
//CODE BY AZIIII

`timescale 1ns / 1ps

module GPU(
    input clk3hz,
    input clr,
    input [31:0]NUMBER,
    output [15:0]dataBus
);
    
    reg [31:0]msgArray;//位移寄存器
    
    //把位移寄存器的高16位传递给数码管显示模块（每个数码管显示四位数据）
    assign dataBus=msgArray[31:16];//此时为四个低位
    
    always@(posedge clk3hz or negedge clr)
        if(!clr)
            msgArray<=NUMBER;
        else begin
        //位移操作：将高四位移动到第四位，同时将27-0位移动到31-4位，这样便实现了一个数据的移动
            msgArray[3:0]<=msgArray[31:28];
            msgArray[31:4]<=msgArray[27:0];
        end
        
endmodule
