module top_module(
    input[31:0]a,
    input[31:0]b,
    output[31:0]sum
);

wire check;
wire cout,cout1,cout2;
wire [15:0]sum1;
wire [15:0]sum2;

add16 a1(a[15:0],b[15:0],0,sum[15:0],check);

add16 s1(a[31:16],b[31:16],0,sum1,cout1);
add16 s2(a[31:16],b[31:16],1,sum2,cout2);

assign sum[31:16]=check?sum2:sum1;
assign cout=check?cout2:cout1;

endmodule