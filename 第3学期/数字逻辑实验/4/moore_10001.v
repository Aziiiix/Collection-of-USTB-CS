//moore_10001
//CODE BY AZIIII

module seqdetea (
    input wire clk,
    input wire clr,
    input wire din,
    output reg dout,
    output reg [2:0]stat
);
reg [2:0]present_state,next_state;
parameter S0=3'b000,S1=3'b001,S2=3'b010,S3=3'b011,S4=3'b100,S5=3'b101;

always @(posedge clk or posedge clr) begin
    if(clr==1)
    present_state<=S0;
    else
    present_state<=next_state;
    stat<=next_state;
end

always @(*) begin
    case(present_state)
    S0: if(din==1)
    next_state<=S1;
    else
    next_state<=S0;
    S1: if(din==0)
    next_state<=S2;
    else
    next_state<=S1;
    S2: if(din==0)
    next_state<=S3;
    else
    next_state<=S1;
    S3: if(din==0)
    next_state<=S4;
    else
    next_state<=S1;
    S4: if(din==1)
    next_state<=S5;
    else
    next_state<=S0;
    S5: if(din==0)
    next_state<=S2;
    else
    next_state<=S1;
    default:next_state<=S0;
    endcase
end

always @(posedge clk) begin
    if(present_state==S5)
    dout<=1;
    else
    dout<=0;
    end

    
endmodule