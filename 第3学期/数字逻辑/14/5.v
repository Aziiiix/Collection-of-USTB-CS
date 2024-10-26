module top_module(
    input clk,
    input reset,    // Synchronous reset
    input in,
    output disc,
    output flag,
    output err);
    
	parameter S0=0, S1=1, S2=2, S3=3, S4=4, S5=5, S6=6, DISC=7, FLAG=8, ERR=9;
    reg [3:0] state, state_next;
    
    always @(*) begin
        case (state)
            S0 : begin
                if (in)  state_next <= S1;
                else 	 state_next <= S0;
            end
            S1 : begin
                if (in)  state_next <= S2;
                else 	 state_next <= S0;
            end
            S2 : begin
                if (in)  state_next <= S3;
                else 	 state_next <= S0;
            end
            S3 : begin
                if (in)  state_next <= S4;
                else 	 state_next <= S0;
            end
            S4 : begin
                if (in)  state_next <= S5;
                else 	 state_next <= S0;
            end
            S5 : begin
                if (in)  state_next <= S6;
                else 	 state_next <= DISC;
            end
            S6 : begin
                if (in)  state_next <= ERR;
                else 	 state_next <= FLAG;
            end
            DISC : begin
                if (in)  state_next <= S1;
                else 	 state_next <= S0;
            end
            FLAG : begin
                if (in)  state_next <= S1;
                else 	 state_next <= S0;
            end
            ERR : begin
                if (in)  state_next <= ERR;
                else 	 state_next <= S0;
            end
        endcase
    end
    
    always @(posedge clk)
        begin
            if (reset) state <= S0;
            else state <= state_next;
        end
    
    assign disc = (state == DISC);
    assign flag = (state == FLAG);
    assign err  = (state == ERR);    
endmodule
