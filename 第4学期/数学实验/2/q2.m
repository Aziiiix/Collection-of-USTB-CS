for a=-50:1:50
    clf
    [x,y]=meshgrid(-10:0.1:10);
    z1=x.^2-y.^2;
    mesh(x,y,z1);
    hold on
    z2=a*ones(size(x))
    mesh(x,y,z2);
    grid on;
    r0=abs(z1-z2)<=0.5;
    xx=r0.*x;
    yy=r0.*y;
    zz=r0.*z2;
    i1=plot3(xx(r0~=0),yy(r0~=0),zz(r0~=0),'r*');
    set(i1,'linewidth',3)
    xlabel('x');ylabel('y');zlabel('z')
    pause(0.1)
end