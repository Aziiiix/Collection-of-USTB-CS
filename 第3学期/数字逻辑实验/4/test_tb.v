
module seqdetea_tb;
  reg clk;
  reg clr;
  reg din;
  wire dout;
  wire [2:0]stat;
    parameter PERIOD=40;
    seqdetea sedetea(
    .clk(clk),
    .clr(clr),
    .din(din),
    .dout(dout),
    .stat(stat)
    );
    
    initial
         begin
             clk = 0;
             forever
                 begin
                     #(PERIOD/2) clk=1;
                     #(PERIOD/2) clk=0;
                   end
              end
     initial
                      begin
                         clk =0;
                         forever
                             begin
                                #(PERIOD/2) clk=1;
                                #(PERIOD/2) clk=0;
                              end
                          end
      initial
                      begin
                         clr=1;
                         forever
                             begin
                                 #50 clr=0;
                             end
                        end
                    initial
                       begin
                           din=0;
                           #240 din=1;
                           #40 din=0;
                           #160 din=1;
                           #80 din=0;
                           #240 din=1;
                           #40 din=0;
                           #40 din=1;
                           #40 din=0;
                           #80 din=1;
                           #40 din=0;
                           #80 din=1;
                           #40 din=0;
                           #40 din=1;
                           #40 din=0;
                           #120 din=1;
                
                       end  
endmodule