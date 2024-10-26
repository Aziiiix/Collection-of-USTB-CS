module top_module(
    input clk,
    input areset,    // State4eshly brainwashed Lemmings walk left.
    input bump_left,
    input bump_right,
    input ground,
    output reg walk_left,
    output reg walk_right,
    output reg aaah );
    reg [1:0]state,next;
    parameter STATE1=0,STATE2=1,STATE3=2,STATE4=3;
    always @(*)
        begin
        case(state)
            STATE1: next = ground? ( bump_left ? STATE2:STATE1):STATE3;
            STATE2: next = ground? ( bump_right? STATE1:STATE2):STATE4;
            STATE3: next = ground? STATE1 : STATE3;
            STATE4: next = ground? STATE2 : STATE4;
        endcase
        end
    always @(posedge clk or posedge areset)
        if(areset) state <= STATE1;
        else state <= next;
    always @(*)
        case(state)
            STATE1:  {walk_left,walk_right,aaah}=3'b100;
            STATE2:  {walk_left,walk_right,aaah}=3'b010;
            STATE3:  {walk_left,walk_right,aaah}=3'b001;
            STATE4:  {walk_left,walk_right,aaah}=3'b001;
        endcase
    
            
endmodule
