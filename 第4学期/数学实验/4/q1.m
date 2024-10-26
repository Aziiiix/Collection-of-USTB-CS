x=[0.10,0.30,0.40,0.55,0.70,0.80,0.95];
y=[15,18,19,21,22.6,23.8,26];
p1=polyfit(x,y,1);
p3=polyfit(x,y,3);
p5=polyfit(x,y,5);

x1=0.1:0.1:1.0;
y1=polyval(p1,x1); 
y3=polyval(p3,x1);
y5=polyval(p5,x1);
plot(x,y,'rp',x1,y1,'--',x1,y3,'k-.',x1,y5)
legend('拟合点','一次拟合','三次拟合','五次拟合');