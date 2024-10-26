clear;clf
p0=[0 0 0]; %追击者起始点
pd=[150 0 150]; %目标初始点；
v2=500; %导弹速度 m/s
hold on
dt=0.01; %时间间隔
xp0=p0(1); yp0=p0(2); zp0=p0(3);%追击者起始点
xd0=pd(1); yd0=pd(2); zd0=p0(3);%目标起始点
times=0; %记录追击的步数
d0=100; %记录追击者和目标之间距离
theta=0;
thr=10; %设置阈值

while(d0>thr) 
theta=pi*dt*times;
xd1=xd0-10*sin(theta);
yd1=yd0;
zd1=zd0-10*(1-cos(theta))+times*2;
plot3([xd0,xd1],[yd0,yd1],[zd0,zd1],'b'); %作目标点运动轨迹
d0=sqrt((xp0-xd0)^2+(yp0-yd0)^2+(zp0-zd0)^2); %当前目标点和追击者距离
cos_ca=(xd0-xp0)/d0; cos_cb=(yd0-yp0)/d0;cos_cy=(zd0-zp0)/d0;
xp1=xp0+v2*cos_ca*dt; yp1=yp0+v2*cos_cb*dt;zp1=zp0+v2*cos_cy*dt; %更新追击者位置
plot3([xp0,xp1],[yp0,yp1],[zp0,zp1],'r'); %追击者运动轨迹
view([1 -1 1]);
v0=sqrt((xd0-xd1)^2+(yd0-yd1)^2+(zp0-zd0)^2)/dt; %飞机速度估计值
pause(0.01);
xp0=xp1; yp0=yp1;zp0=zp1; %追击者重新赋初值
xd0=xd1; yd0=yd1;zd0=zd1; %目标点重新赋初值
times=times+1;
end
time=times*dt;