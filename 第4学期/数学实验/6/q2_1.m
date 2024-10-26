x1=-5:0.1:5;
p1=normpdf(x1,0,0.4);p2=normpdf(x1,0,1);
p3=normpdf(x1,-2,2);p4=normpdf(x1,1,2);
subplot(221)
plot(x1,p1,x1,p2,x1,p3,x1,p4);
title('正态分布的概率密度图');

x2=0:0.1:25;
o1=chi2pdf(x2,4);o2=chi2pdf(x2,9);
subplot(222)
plot(x2,o1,x2,o2);
title('χ^2分布的概率密度图');

x3=-5:0.1:5;
i1=tpdf(x3,6);i2=tpdf(x3,40);i3=normpdf(x3,0,1);
subplot(223)
plot(x3,i1,x3,i2,x3,i3);
title('t分布的概率密度图');

x4=0:0.01:5;
u1=fpdf(x4,4,1);u2=fpdf(x4,4,9);
u3=fpdf(x4,9,4);u4=fpdf(x4,9,1);
subplot(224)
plot(x4,u1,x4,u2,x4,u3,x4,u4);
title('F分布的概率密度图');