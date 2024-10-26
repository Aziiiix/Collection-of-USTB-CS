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
    parameter STATE1=0,STATE2=1,STATE3=2,STATE4=3,STATE5=4,STATE6=5;
    reg [2:0]state,next;
   
    always @(*)
        begin
            case(state)
                STATE1: next = ground? (dig? STATE5 : (bump_left? STATE2:STATE1) ):STATE3;
                STATE2: next = ground? (dig? STATE6 : (bump_right?STATE1:STATE2) ):STATE4;
                STATE3: next = ground? STATE1 : STATE3;
                STATE4: next = ground? STATE2 : STATE4;
                STATE5: next = ground? STATE5 : STATE3;
                STATE6: next = ground? STATE6 : STATE4;
            endcase
        end
    always @(posedge clk or posedge areset)
        if(areset) state <= STATE1;
    	else state <= next;
    always @(*)
        case(state)
            STATE1: {walk_left,walk_right,aaah,digging} = 4'b1000;
            STATE2: {walk_left,walk_right,aaah,digging} = 4'b0100;
            STATE3: {walk_left,walk_right,aaah,digging} = 4'b0010;
            STATE4: {walk_left,walk_right,aaah,digging} = 4'b0010;
            STATE5: {walk_left,walk_right,aaah,digging} = 4'b0001;
            STATE6: {walk_left,walk_right,aaah,digging} = 4'b0001;
        endcase
endmodule
