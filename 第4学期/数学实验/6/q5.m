close all; clear all; clc

figure('Position',[50,50,600,500],'Name','double integration')

f=@(x,y) exp(power(x+y,2));

Q1=dblquad(f,0,1,0,1,1.0e-3)

x=linspace(0,1);y=linspace(0,1);

ff=exp(power(x+y,2));

plot3(x,y,ff,'r','LineWidth',3)

grid on; view(35,35)

xlabel('x','FontSize',15); ylabel('y','FontSize',15)