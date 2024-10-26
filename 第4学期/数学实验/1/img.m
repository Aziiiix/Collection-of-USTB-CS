x1=-pi:0.1:pi;
y1=x1.*cos(x1);
x2=pi:0.1:4*pi;
y2=x2.*tan(1./x2).*sin(x2.^3);
x3=1:0.1:8;
y3=exp(1./x3).*sin(x3);

plot(x1,y1,'r-',x2,y2,'g-',x3,y3,'b-');


title('第二题//mhl')
xlabel('x轴'),ylabel('y轴')
gtext('y1=xcos(x)'),gtext('y2=xtan(1/x)sin(x^3)'),gtext('y3=e^(1/x)sinx')
legend('y1=xcos(x)','y2=xtan(1/x)sin(x^3)','y3=e^(1/x)sinx')
axis([-pi,4*pi+1,-4,4]);