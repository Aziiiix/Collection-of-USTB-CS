//keyled.v
//CODE BY AZIIII

`timescale 1ns / 1ps

module keyled(
     input clk100mhz,//100mhz时钟信号
     input [4:0]key_in,//按键的输入
     output [31:0]NUMBER,
     output reg reset
    );
    
    reg [25:0] count_high;//高电平延时判断信号
    reg [31:0] key_out;//储存按键的输出
    parameter SAMPLE_TIME = 500000;//延迟时间，此处为5ms
    assign NUMBER = key_out;//同步数据
           
    //高电平判断
    always @(posedge clk100mhz)
       if(key_in==0)//未按下时置零
            count_high<=0;
       else
            count_high<=count_high +1;//按下时开始计数
            
    always @(posedge clk100mhz)
       if(count_high == SAMPLE_TIME&&key_in[0])//按下5ms后
       begin
           if(reset==0)//低位输入时
             begin
                key_out[19:16]<=key_out[19:16]+1;
                if(key_out[19:16]==9)//大于9则置零
                   key_out[19:16]<=0;
             end
           else if(reset==1)//高位输入时
             begin
                key_out[3:0]<=key_out[3:0]+1;
                if(key_out[3:0]==9)
                   key_out[3:0]<=0;
             end
       end
                      
       else if(count_high == SAMPLE_TIME&&key_in[1])
       begin
          if(reset==0)
            begin
               key_out[23:20]<=key_out[23:20]+1;
               if(key_out[23:20]==9)
                  key_out[23:20]<=0;
            end
          else if(reset==1)
            begin
               key_out[7:4]<=key_out[7:4]+1;
               if(key_out[7:4]==9)
                  key_out[7:4]<=0;
            end
       end
          
       else if(count_high == SAMPLE_TIME&&key_in[2])
       begin
          if(reset==0)
            begin
              key_out[27:24]<=key_out[27:24]+1;
              if(key_out[27:24]==9)
                 key_out[27:24]<=0;
            end
          else if(reset==1)
            begin
              key_out[11:8]<=key_out[11:8]+1;
              if(key_out[11:8]==9)
                 key_out[11:8]<=0;
            end
       end
       
       else if(count_high == SAMPLE_TIME&&key_in[3])
       begin
        if(reset==0)
          begin
             key_out[31:28]<=key_out[31:28]+1;
             if(key_out[31:28]==9)
                key_out[31:28]<=0;
          end
        else if(reset==1)
          begin
             key_out[15:12]<=key_out[15:12]+1;
             if(key_out[15:12]==9)
                key_out[15:12]<=0;
          end
     end
     
     else if(count_high == SAMPLE_TIME&&key_in[4])
     begin
       if(reset==0)//由低位切换到高位输入
          begin
             reset<=1;
          end
       else if(reset==1)//高位输入时，再次按下即NUMBER清零
          begin
             reset<=0;
             key_out<=0;
          end      
       end
     
endmodule
