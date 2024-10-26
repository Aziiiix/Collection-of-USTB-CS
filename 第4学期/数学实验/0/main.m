clc;
clf;

%设置点数
n=10;

%生成1行n列用于储存随机坐标
x=zeros(1,n);
y=zeros(1,n);

for i=1:n
    %随机生成坐标
    x(i)=randn*10;
    y(i)=randn*10;
    %画出坐标散点图
    scatter(x(i),y(i),'b');
    hold on
    %标记各点序号
    text(x(i)+1,y(i)+1,num2str(i));
end

%n*n矩阵distance储存各点间的距离
distance=zeros(n);

%计算出各点的距离并存放于矩阵distance中
for i=1:n
    for j=1:n
        distance(i,j)=sqrt( ( x(i) - x(j) ) ^ 2 + ( y(i) - y(j) ) ^ 2);
    end
end

%初始化矩阵1~n用于储存路线\排序
line=1:1:n;
line(1)=1;
sequence=1:1:n;
%计数
counter=1;

%共排序n-2次
for a=1:(n-2)
    %删除上一个排序点
    sequence(:,1)=[];
    %存放剩下各点与当前点的距离
    dis=zeros(1,(n-a));
    %通过distance查找各点与当前点距离
    for b=1:(n-a)
        dis(b)=distance(counter,sequence(b));
    end
    num_min = find( dis == min(dis) ); 
    %中间变量互换位置
    st=sequence(1);
    sequence(1)=sequence(num_min);
    sequence(num_min)=st;
    %更新计数
    counter=sequence(1);
    %更新路线
    line(a+1)=sequence(1);
end

%填补终点
line(n)=sequence(2);
%虚线相连得到最佳路径
plot(x(line),y(line),'--o') ;
title('贪心算法计算最优路径');
grid on
