//segMsg.v
//CODE BY AZIIII

`timescale 1ns / 1ps

module segMsg(
     input clk190hz,
     input [15:0]dataBus,//四位滚动的数据总线
     input [31:0]NUMBER,//学号
     input reset,
     input clr,
     output reg [3:0]pos,//数码管前四位
     output reg [3:0]pos1,//数码管后四位
     output reg [7:0]seg,//LED1
     output reg [7:0]seg1//LED0
);

     reg [1:0]posC;//数码管计数器
     reg [3:0]dataP;//数据的一部分
     
     always@(posedge clk190hz)
     //后四位显示
     begin
       case(posC)
          //将数据总线的3：0位显示在第8个数码管上/8
          0:begin
              pos   <=4'b0001;
              dataP <=dataBus[3:0];
            end
          //将数据总线的7：4位显示在第7个数码管上/7
          1:begin
               pos   <=4'b0010;
               dataP <=dataBus[7:4];
             end
          //将数据总线的11：8位显示在第6个数码管上/6
          2:begin
                pos   <=4'b0100;
                dataP <=dataBus[11:8];
              end
          //将数据总线的15：12位显示在第5个数码管上/5
          3:begin
                 pos   <=4'b1000;
                 dataP <=dataBus[15:12];
             end
         endcase
         posC=posC+1;
       end
       //解码数据来控制数码管的每一段（这里取0-9十个数字外加三个特殊显示）
       always@(dataP)
          case(dataP)
              0: seg=8'b0011_1111;
              1: seg=8'b0000_0110;
              2: seg=8'b0101_1011;
              3: seg=8'b0100_1111;
              4: seg=8'b0110_0110;
              5: seg=8'b0110_1101;
              6: seg=8'b0111_1101;
              7: seg=8'b0000_0111;
              8: seg=8'b0111_1111;
              9: seg=8'b0110_1111;
              10:seg=8'b0100_0000;
              11:seg=8'b0000_0000;
              default:seg=8'b0000_1000;
          endcase
          
          reg [1:0]posC1;//数码管计数器
          reg [3:0]dataP1;//数据的一部分
          
          always@(posedge clk190hz)
          //前四位显示
          begin
              if(!clr)begin//数据输入状态
                  case(posC1)
               
               0:begin
                   pos1   <=4'b0001;//第4个数码管
                   if(reset==1)//输入高位时显示NUMBER[3:0]
                   dataP1 <= NUMBER[3:0];
                   else if(reset==0)//输入低位时显示0000_0100
                   dataP1 <= 11;
                 end
               
               1:begin
                   pos1   <=4'b0010;//3
                   if(reset==1)
                   dataP1 <= NUMBER[7:4];
                   else if(reset==0)
                   dataP1 <= 11;
                 end
               
               2:begin
                   pos1   <=4'b0100;//2
                   if(reset==1)
                   dataP1 <= NUMBER[11:8];
                   else if(reset==0)
                   dataP1 <= 11;
                 end
               
               3:begin
                      pos1   <=4'b1000;//1
                      if(reset==1)
                      dataP1 <= NUMBER[15:12];
                      else if(reset==0)
                      dataP1 <= 11;
                 end
             endcase
             posC1=posC1+1;
              end

              else begin
                  case(posC1)//数据滚动状态
               //前四位显示0100_0000 后四位数据滚动
               0:begin
                   pos1   <=4'b0001;
                   dataP1 <= 10;
                 end
               
               1:begin
                   pos1   <=4'b0010;
                   dataP1 <= 10;
                 end
               
               2:begin
                   pos1   <=4'b0100;
                   dataP1 <= 10;
                 end
               
               3:begin
                      pos1   <=4'b1000;
                      dataP1 <= 10;
                 end
             endcase
             posC1=posC1+1;
              end
          end

          always@(dataP1)
                    case(dataP1)
                        0: seg1=8'b0011_1111;
                        1: seg1=8'b0000_0110;
                        2: seg1=8'b0101_1011;
                        3: seg1=8'b0100_1111;
                        4: seg1=8'b0110_0110;
                        5: seg1=8'b0110_1101;
                        6: seg1=8'b0111_1101;
                        7: seg1=8'b0000_0111;
                        8: seg1=8'b0111_1111;
                        9: seg1=8'b0110_1111;
                        10:seg1=8'b0100_0000;
                        11:seg1=8'b0000_1000;
                        default:seg1=8'b0001_1000;
                    endcase
endmodule