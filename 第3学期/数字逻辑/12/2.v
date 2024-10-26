
module add1(
    input a,
    input b,
    input cin,
    output sum,
    output cout
);

assign sum=a^b^cin;
assign cout=(a&b)|(a&cin)|(b&cin);

endmodule

module top_module(
    input [31:0]a,
    input [31:0]b,
    output [31:0]sum
);

wire ccin,ccout;


add16 a1(
    .a(a[15:0]),
    .b(b[15:0]),
    .cin(0),
    .sum(sum[15:0]),
    .cout(ccin)
);

add16 a2(
    a[31:16],b[31:16],ccin,
    sum[31:16],ccout
);

endmodule