module top_module (
    input [4:0] a, b, c, d, e, f,
    output [7:0] w, x, y, z );

    assign w[7:3]=a[4:0];
    assign w[2:0]=b[4:2];
    assign x[7:6]=b[1:0];
    assign x[5:1]=c[4:0];
    assign x[0]=d[4];
    assign y[7:4]=d[3:0];
    assign y[3:0]=e[4:1];
    assign z[7]=e[0];
    assign z[6:2]=f[4:0];
    assign z[1:0]=2'b11;

    //assign {w,x,y,z} = {a,b,c,d,e,f,2'b11};
    
endmodule
