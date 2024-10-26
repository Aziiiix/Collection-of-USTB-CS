module top_module(
    input clk,
    input areset,    // Freshly brainwashed Lemmings walk left.
    input bump_left,
    input bump_right,
    input ground,
    output reg walk_left,
    output reg walk_right,
    output reg aaah);

wire stat;

always @(posedge clk or posedge areset) begin

if(!ground)begin
aaah=1;
walk_left<=0;
walk_right<=0;
end
else begin

    aaah=0;

    if(areset)begin
        walk_left<=1;
        walk_right<=0;
    end
    if(bump_left==1&&bump_right==1)begin
        walk_left<=~walk_left;
        walk_right<=~walk_right;
    end
    else begin
    if(bump_right)begin
        walk_left<=1;
        walk_right<=0;
    end
    if(bump_left)begin
        walk_left<=0;
        walk_right<=1;
    end
end
end
end


endmodule