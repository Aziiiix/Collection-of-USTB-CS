//clkDiv.v

`timescale 1ns / 1ps

module clkDiv(
     input clk100mhz, 
     output clk190hz, 
     output clk10000hz
     );

     reg[19:0]count = 0;
     assign clk190hz = count[18];//第19位分频190HZ
     assign clk10000hz = count[9];//第10位分频10000HZ

     always@(posedge clk100mhz)
          count <= count + 1;

endmodule

