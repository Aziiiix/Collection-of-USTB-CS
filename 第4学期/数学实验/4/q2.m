x=[10,15,20,25,30];
y=[25.2,29.8,31.2,31.7,29.4];
xi=10:1:30;
yi1=interp1(x,y,xi,'*nearest');
yi2=interp1(x,y,xi,'*linear');
yi3=interp1(x,y,xi,'*spline');
yi4=interp1(x,y,xi,'*pchip');
plot(x,y,'ro',xi,yi1,'--',xi,yi2,'-',xi,yi3,'k.-',xi,yi4,'m:')
legend('原始数据','最近点插值','线性插值','样条插值','立方插值')

sum1=interp1(x,y,18,'*nearest');
sum2=interp1(x,y,18,'*linear');
sum3=interp1(x,y,18,'*spline');
sum4=interp1(x,y,18,'*pchip');
sum=(sum1+sum2+sum3+sum4)/4;
disp(['X=18 Y=' num2str(sum)]);

sum1=interp1(x,y,26,'*nearest');
sum2=interp1(x,y,26,'*linear');
sum3=interp1(x,y,26,'*spline');
sum4=interp1(x,y,26,'*pchip');
sum=(sum1+sum2+sum3+sum4)/4;
disp(['X=26 Y=' num2str(sum)]);