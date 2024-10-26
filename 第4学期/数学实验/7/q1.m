clear;clc;
vd=200; %飞机速度
v0=500; %导弹速度
c=1500; %初始距离
p0=[0 0 0]; %导弹起始点
pd=[c 0 c]; %飞机起始点
hold on
dt=0.01; %时间间隔
xp0=p0(1); yp0=p0(2); zp0=p0(3);%导弹起始点横纵坐标
xd0=pd(1); yd0=pd(2); zd0=pd(3);%飞机起始点横纵坐标
times=0; %记录追击的步数，初始值为0
thr=10; %设置阈值
d0=c; %记录追击者 导弹和目标 飞机之间距离
h1=plot3(0,0,0);
h2=plot3(0,0,0);
axis([0 1600 0 1600 0 2000]);
view([1 -1 1]);

while(d0>thr) 
xd1=xd0; %飞机直线运动横坐标
yd1=yd0+vd*dt; %飞机直线运动纵坐标
zd1=zd0;
times=times+1;
plot3([xd0,xd1],[yd0,yd1],[zd0,zd1],'b','linewidth',2); %作目标点飞机运动轨迹
%追击者指向目标位置 %目标当前位置(xd0,yd0),追击者当前位置(xp0,yp0) 
d0=sqrt((xp0-xd0)^2+(yp0-yd0)^2+(zp0-zd0)^2); %当前目标点和追击者距离
cos_ca=(xd0-xp0)/d0; cos_cb=(yd0-yp0)/d0;cos_cy=(zd0-zp0)/d0;
xp1=xp0+v0*cos_ca*dt; yp1=yp0+v0*cos_cb*dt;zp1=zp0+v0*cos_cy*dt; %更新追击者 导弹 位置
plot3([xp0,xp1],[yp0,yp1],[zp0,zp1],'g','linewidth',2); %追击者 导弹 运动轨迹
set(h1,'xdata',xp1,'ydata',yp1,'zdata',zp1,'color','g','markersize',12) %导弹
set(h2,'xdata',xd1,'ydata',yd1,'zdata',zp1,'color','b','markersize',10,'marker','^','markerfacecolor','b') %飞机
pause(0.01);
xp0=xp1; yp0=yp1;zp0=zp1; %追击者重新赋初值
xd0=xd1; yd0=yd1;zd0=zd1; %目标点重新赋初值
end
time=times*dt; %计算追击时间。时间步长*dt