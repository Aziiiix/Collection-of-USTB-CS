x=1:.1:2;
y=[2.1,3.2,2.1,2.5,3.2,3.5,3.4,4.1,4.7,5.0,4.8];
p2=polyfit(x,y,2) 
p3=polyfit(x,y,3);
p7=polyfit(x,y,7);

x1=1:.01:2;
y2=polyval(p2,x1); 
y3=polyval(p3,x1);
y7=polyval(p7,x1);
plot(x,y,'rp',x1,y2,'--',x1,y3,'k-.',x1,y7)