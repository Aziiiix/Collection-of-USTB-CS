module top_module(
    input clk,
    input areset,    // Asynchronous reset to state B
    input in,
    output reg out);

	parameter A = 1'b0,
    		  B = 1'b1;
    
    reg c;
    reg n;
    

    always @(posedge clk or posedge areset) begin
        if (areset == 1'b1)
            c <= B;
        else
            c <= n;
    end
            

    always @(*) begin


        case(c)
            A : n<=in?A:B;
            B : n<=in?B:A;
            default: n = B;
        endcase
    end

    always @(posedge clk or posedge areset) begin
        if (areset == 1'b1)
            out <= 1'b1;
        else begin
            case (n)
                A : out <= 1'b0;
                B : out <= 1'b1;
            endcase
        end
    end

endmodule