module top_module(
    input clk,
    input areset,    // State4eshly brainwashed Lemmings walk left.
    input bump_left,
    input bump_right,
    input ground,
    input dig,
    output reg walk_left,
    output reg walk_right,
    output reg aaah,
    output reg digging );
	parameter STATE1=0,STATE2=1,STATE3=2,STATE4=3,STATE5=4,STATE6=5,State7 = 6;
    reg [64:0]counter;
    reg [2:0]state,next;
    always @(*)
        case(state)
            STATE1: next = ground ? (dig ? STATE5: (bump_left?STATE2:STATE1)) : STATE3;
            STATE2: next = ground ? (dig ? STATE6: (bump_right?STATE1:STATE2)) : STATE4;
            STATE3: next = ground ? (counter>19? State7 : STATE1) : STATE3;
            STATE4: next = ground ? (counter>19? State7 : STATE2): STATE4;
            STATE5: next = ground ? STATE5 : STATE3;
            STATE6: next = ground ? STATE6 : STATE4;
            State7:next = State7;
        endcase
    always @(posedge clk or posedge areset)
        begin
        if(areset) state<=STATE1;
        else if  ( state==STATE3 || state == STATE4 )
                          begin
                              state <= next;
                              counter = counter + 1;
                          end
 
        else begin 
            state <= next;
            counter =0;
        end
        end
            
    always @(*)
        case(state)
            STATE1 : {walk_left,walk_right,aaah,digging} = 4'b1000;
            STATE2 : {walk_left,walk_right,aaah,digging} = 4'b0100;
            STATE3 : {walk_left,walk_right,aaah,digging} = 4'b0010;
            STATE4 : {walk_left,walk_right,aaah,digging} = 4'b0010;
            STATE5 : {walk_left,walk_right,aaah,digging} = 4'b0001;
            STATE6 : {walk_left,walk_right,aaah,digging} = 4'b0001;
            State7: {walk_left,walk_right,aaah,digging} = 4'b0000;
        endcase 
    
endmodule
