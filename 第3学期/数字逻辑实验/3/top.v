//top.v
//CODE BY AZIIII

module top(
    input clk100mhz,
    input clr,
    input [4:0]key_in,
    output [3:0]pos,
    output [3:0]pos1,
    output [7:0]seg,
    output [7:0]seg1
    );
    
    wire clk190hz;//将分频模块的190hz信号连接到数码管显示模块
    wire clk3hz;//将分频模块的3hz信号连接到处理显示GPU模块
    wire [15:0]dataBus;//将处理模块处理后的数据连接到数码管显示模块
    wire [31:0]NUMBER;//存入学号数据
    wire reset;
    
    keyled U1(clk100mhz,key_in,NUMBER,reset);//输入数据
    clkDiv U2(clk100mhz,clk190hz,clk3hz);//分频
    GPU    U3(clk3hz,clr,NUMBER,dataBus);//滚动
    segMsg U4(clk190hz,dataBus,NUMBER,reset,clr,pos,pos1,seg,seg1);//显示
    
endmodule