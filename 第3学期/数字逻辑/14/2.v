module top_module(
    input clk,
    input areset,    // Freshly brainwashed Lemmings walk left.
    input bump_left,
    input bump_right,
    input ground,
    output reg walk_left,
    output reg walk_right,
    output reg aaah );
    reg [1:0]state,next;
    parameter WL=0,WR=1,FL=2,FR=3;
    always @(*)
        begin
        case(state)
            WL: next = ground? ( bump_left ? WR:WL):FL;
            WR: next = ground? ( bump_right? WL:WR):FR;
            FL: next = ground? WL : FL;
            FR: next = ground? WR : FR;
        endcase
        end
    always @(posedge clk or posedge areset)
        if(areset) state <= WL;
        else state <= next;
    always @(*)
        case(state)
            WL:  {walk_left,walk_right,aaah}=3'b100;
            WR:  {walk_left,walk_right,aaah}=3'b010;
            FL:  {walk_left,walk_right,aaah}=3'b001;
            FR:  {walk_left,walk_right,aaah}=3'b001;
        endcase
    
            
endmodule
 