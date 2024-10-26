function dx=appollo(t,x)
mu=1/82.45;
mustar=1-mu;
r1=sqrt((x(1)+mu)^2+x(3)^2);
r2=sqrt((x(1)-mustar)^2+x(3)^2);
dx=[x(2)
2*x(4)+x(1)-mustar*(x(1)+mu)/r1^3-mu*(x(1)-mustar)/r2^3
x(4)
-2*x(2)+x(3)-mustar*x(3)/r1^3-mu*x(3)/r2^3];