module top_module (
    input x,input y,output z
);
    wire z1,z2,z3,z4;

    A A(
        .x(x),
        .y(y),
        .z(z1)
    );
    B B(
        .x(x),
        .y(y),
        .z(z2)
    );

    assign z3=z1;
    assign z4=z2;

    wire s1,s2;
    assign s1=z1|z2;
    assign s2=z3&z4;

    assign z=(s1&(~s2))|((~s1)&s2);

endmodule