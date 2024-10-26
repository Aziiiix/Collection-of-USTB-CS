module seqdetea_tb ;
    reg clk;
    reg clr;
    reg din;
    wire dout;
    wire [2:0]stat;
    parameter PERIOD=40;
    seqdetea seqetea(
        .clk(clk),
        .clr(clr),
        .din(din),
        .dout(dout),
        .stat(stat)
    );
initial begin
    clk=0;
    forever begin
        #(PERIOD/2)clk =1;
        #(PERIOD/2)clk =0;
    end
end

initial begin
    clr=1;
    forever begin
        #50 clr=0;
    end
end

reg [4:0] test;
reg [2:0] counter;

initial begin
    assign test=5'b00000;
    assign counter=3'b000;
end

always @(*) begin

    #40 din<=test[counter];
    if(counter<4)
    counter<=counter+1;
    else
    counter<=0;


end
    
endmodule