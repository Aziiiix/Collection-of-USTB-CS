module GPU_tb ();

reg clk;
reg clr;

wire [15:0]dataBus;

initial begin
    clk=0;
    clr=0;
    #100 clr=1;
end

always #5 clk=~clk;

endmodule