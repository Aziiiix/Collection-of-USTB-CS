module top;
reg clk,rst;
wire [3:0] dout;

counter cnt (dout,clk,rst);

initial begin
    clk=0;
    rst=1;
    #15 rst=0;
    #10 rst=1;
    #55 $finish;
end

always #10 clk=~clk;

initial begin
    $monitor($time,,"%b %b %b",rst,clk,dout);
end

endmodule