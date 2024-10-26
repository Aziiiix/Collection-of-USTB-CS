clear;
[xmin,ymin]=fminbnd('(1./((x-2).^2+3)+1./(3*(x-5).^2+4)+1./(2*(x-1).^2+1))*(-1)',-3,3);
disp(xmin);disp(ymin);