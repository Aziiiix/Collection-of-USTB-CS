//GPU_tb.v
//CODE BY AZIIII

module GPU_tb();

     reg clk;
     reg clr;
     wire [15:0]dataBus;
     wire [31:0]NUMBER=32'd42024202;
     
     initial 
       begin
        clk=0;
        clr=0;
        #20 clr=1;
       end
        always #5 clk=~clk;
        
        GPU tb1(clk,clr,NUMBER,dataBus);

endmodule
