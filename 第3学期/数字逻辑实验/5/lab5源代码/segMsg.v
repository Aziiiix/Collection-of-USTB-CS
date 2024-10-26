//segMsg.v
//CODE BY AZIIII

module segMsg (
    input clk,
    input state_cal,
    input state_reset,

    input [3:0]weight,
    input [3:0]per,
    input [7:0]price,
    input [7:0]times,
    input [15:0]sum,

    output reg [3:0]pos1,
    output reg [7:0]seg1,
    output reg [3:0]pos2,
    output reg [7:0]seg2
);
    
    reg [1:0]posC=2'b0;
    reg [3:0]dataP=4'b0;

    always @(posedge clk) begin
        if(state_reset)begin
            pos1<=4'b1111;
            dataP<=0;
        end

        else begin
            case (posC)
                0: begin
                    pos1<=4'b1000;
                    if(state_cal==0)begin
                        if(weight>=10)
                        dataP<=1;
                        else
                        dataP<=0;
                    end
                    else dataP<=10;
                end
                1: begin
                    pos1<=4'b0100;
                    if(state_cal==0)begin
                        if(weight>=10)
                        dataP<=weight-10;
                        else
                        dataP<=weight;
                    end
                    else dataP<=11;
                end
                2: begin
                    pos1<=4'b0010;
                    if(state_cal==0)begin
                        if(per>=10)
                        dataP<=1;
                        else
                        dataP<=0;
                    end
                    else begin
                        if(times>=10)
                        dataP<=times/10;
                        else
                        dataP<=0;
                    end
                end
                3: begin
                    pos1<=4'b0001;
                    if(state_cal==0)begin
                        if(per>=10)
                        dataP<=per-10;
                        else
                        dataP<=per;
                    end
                    else begin
                        if(times>=10)
                        dataP<=times%10;
                        else
                        dataP<=times;
                    end
                end
                default: pos1<=4'b0000;
            endcase
            posC<=posC+1;
        end
    end

    always@(dataP)
     case(dataP)
        0:seg1=8'b0011_1111;
        1:seg1=8'b0000_0110;
        2:seg1=8'b0101_1011;
        3:seg1=8'b0100_1111;
        4:seg1=8'b0110_0110;
        5:seg1=8'b0110_1101;
        6:seg1=8'b0111_1101;
        7:seg1=8'b0000_0111;
        8:seg1=8'b0111_1111;
        9:seg1=8'b0110_1111;
        10:seg1=8'b0111_0111;
        11:seg1=8'b0011_1001;
        default:seg1=8'b0000_1000;
        endcase


    reg [1:0]posC1=2'b00;
    reg [3:0]dataP1=4'b0000;

    always @(posedge clk) begin
        if(state_reset)begin
            pos2<=4'b1111;
            dataP1<=0;
        end

        else begin
            case (posC1)
                0: begin
                    pos2<=4'b0001;
                    if(state_cal==0)
                    dataP1<=price%10;
                    else
                    dataP1<=sum%10;
                end
                1: begin
                    pos2<=4'b0010;
                    if(state_cal==0)
                    dataP1<=(price/10)%10;
                    else
                    dataP1<=(sum/10)%10;
                end
                2: begin
                    pos2<=4'b0100;
                    if(state_cal==0)
                    dataP1<=(price/100)%10;
                    else
                    dataP1<=(sum/100)%10;
                end
                3: begin
                    pos2<=4'b1000;
                    if(state_cal==0)
                    dataP1<=0;
                    else
                    dataP1<=(sum/1000)%10;
                end
                default: pos2<=4'b0000;
            endcase
            posC1<=posC1+1;
        end
    end

    always@(dataP1)
     case(dataP1)
        0:seg2=8'b0011_1111;
        1:seg2=8'b0000_0110;
        2:seg2=8'b0101_1011;
        3:seg2=8'b0100_1111;
        4:seg2=8'b0110_0110;
        5:seg2=8'b0110_1101;
        6:seg2=8'b0111_1101;
        7:seg2=8'b0000_0111;
        8:seg2=8'b0111_1111;
        9:seg2=8'b0110_1111;
        10:seg2=8'b0111_0111;
        11:seg2=8'b0011_1001;
        default:seg2=8'b0000_1000;
        endcase


endmodule