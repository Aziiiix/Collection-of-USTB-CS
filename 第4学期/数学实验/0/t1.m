%用贪心算法模拟出随机产生的30个点间的最短路径
%大家在学习代码的时候希望能设置好断点，及时查看工作区矩阵的变化，真的很有帮助哦！clc;
clear all;   %清屏，清除工作区，关闭所有窗口
close all;n=10;           %设置点数
x = zeros(1,n);                           %产生一个行向量存储坐标
y = zeros(1,n);

luxian = 1:1:n;                           %生成1到n的矩阵，存储路线
paixu = 1:1:n;for i = 1 : n                             

    x(i) = randn * 10 ;                  %生成正态分布的随机坐标点  
    y(i) = randn * 10 ;
    
    scatter(x(i),y(i),'b');            %画出散点图
    hold on
    text(x(i)+1,y(i)+1,num2str(i))     %用text做好标记，
end

d = zeros(n) ;       %生成一个n*n的矩阵用来存储点与点之间的距离，这句其实偶去掉也行
                     %为了好理解就留着了

for i = 1 : n 
    for j = 1 : n
          %计算点与点之间的距离，对角线都是零啦
        d(i,j) = sqrt( ( x(i) - x(j) ) ^ 2 + ( y(i) - y(j) ) ^ 2);  
        
    end
end

luxian(1) = 1;                             %设置起点，路线的起点是1
num = 1;

for a = 1:(n-2)                         %去除起点和终点需要n-2次判断
    
paixu(:,1)=[];                       %删除上一个最优点          
dis = zeros(1,(n-a));                %用来存剩下各个点的距离

   for b = 1:(n-a)                     %用来获取剩下各个点的距离

        dis(b) = d (num, paixu(b));       

   end

num1 = find( dis == min(dis) );     %根据距离最小得到最优点位置

t = paixu(1);                      %通过中间变量互换位置

    paixu(1) = paixu(num1);       %最优点位置换到第一个

    paixu(num1) = t;           
    
    num = paixu(1);                    %获取下次进行操作的数

    luxian(a+1) = paixu(1);              %将最优点存入luxian数组（空出开头）

end

%运行完上述代码num1的值只有1或者2
%这段代码的目的是把所有点补全
%if num1==1
 %    luxian(n) = paixu(num1+1);       
%elseif num1==2
%    luxian(n) = paixu(num1); 
%end

luxian(n) = paixu(2);           %补上最后一个点

plot(x(luxian),y(luxian),'--o') ;            %标出点用虚线相连得到路径
title('贪心算法计算最优路径');
grid on