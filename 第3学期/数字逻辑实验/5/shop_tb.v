module shop_tb ();

reg clk;
reg cal,reset;

reg[3:0]weight,per;
reg[7:0]price,times;
reg[15:0]sum;
reg s_cal,s_reset;

always #5 clk=~clk;

initial begin
    weight<=4'b101;
    per<=4'b0011;
    cal<=0;
    reset<=0;
    price<=4'b0;
    times<=4'b0;
    sum<=16'b0;
end

always @(posedge clk) begin
    shop (clk,cal,reset,weight,per,price,times,sum,s_cal,s_reset);
end
    
endmodule