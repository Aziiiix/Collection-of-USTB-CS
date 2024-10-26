subplot(2,2,1)
xc=0;yc=0;zc=0;
xr=3;yr=4;zr=2;
n=30;
[x,y,z]=ellipsoid(xc,yc,zc,xr,yr,zr,n);
surf(x,y,z)
view(3)
xlabel('x轴'),ylabel('y轴'),zlabel('z轴')
title('x^2/9+y^2/16+z^2/4=1立体图//mhl')

subplot(2,2,2)
surf(x,y,z);
view(2);
title('俯视图');
xlabel('x轴'),ylabel('y轴')

subplot(2,2,3);surf(x,y,z);
AZ=180;EL=0;view([AZ,EL])
title('正视图');
xlabel('x轴'),zlabel('z轴')

subplot(2,2,4);surf(x,y,z);
AZ=90;EL=0;view([AZ,EL])
colormap default;
title('左视图');
ylabel('y轴'),zlabel('z轴')