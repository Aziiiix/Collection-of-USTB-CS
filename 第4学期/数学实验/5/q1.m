x=0:pi/80:pi/4;
y=1./(1-sin(x));
format long
z1=sum(y(1:length(x)-1))*h; %左矩形公式
z2=sum(y(2:length(x)))*h; %右矩形公式
z3=trapz(x,y); %复合梯形公式
z4=quad('1./(1-sin(x))',0,pi/4);%复合辛普森公式
format short
c=sqrt(2); %c=根号2
u1=z1-c;
u2=z2-c;
u3=z3-c;
u4=z4-c;
disp(['u1=' num2str(u1) ' u2=' num2str(u2) ' u3=' num2str(u3) ' u4=' num2str(u4)]);