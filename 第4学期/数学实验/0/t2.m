%% 清空环境
clc
clear

%% 数据初始化
%下载数据
load  HeightData

%网格划分，将x和y划分成21份，将z划分成10份（点与点之间相隔200m）
LevelGrid=10;
PortGrid=21;

%起点终点网格点 
starty=10;starth=4;
endy=8;endh=5;
m=1;
%算法参数
PopNumber=10;      %种群个数
iter_max = 100;
BestFitness=[];    %最佳个体
%初始信息素
pheromone=ones(21,21,21);
rou = 0.2;   %信息素衰减系数
 
%% 循环寻找最优路径
for iter=1:iter_max  
    % 路径搜索
    [path,pheromone]=searchpath(PopNumber,LevelGrid,PortGrid,pheromone,HeightData,starty,starth,endy,endh); 
    
    %适应度值计算更新
    fitness=CacuFit(path);                               
    [newbestfitness,newbestindex]=min(fitness);  
    if iter == 1
        bestfitness = newbestfitness;
        bestpath = path(newbestindex,:); 
    end 
        
    if newbestfitness < bestfitness   %将循环结果和初始值比较
          bestfitness = newbestfitness;
          bestpath = path(newbestindex,:);
    end 
    
    BestFitness = [BestFitness;bestfitness];
    %更新信息素
    cfit = 100/bestfitness;
    for i = 2:PortGrid-1
        pheromone(i,bestpath(i*2-1),bestpath(i*2))=(1-rou)* ...
            pheromone(i,bestpath(i*2-1),bestpath(i*2))+rou*cfit;
    end
end

%% 最佳路径
for i=1:21
    a(i,1)=bestpath(i*2-1);  %将坐标点按行排布
    a(i,2)=bestpath(i*2);
end
x=1:21;
y=1:21;
[x1,y1]=meshgrid(x,y);
figure(1)
mesh(x1,y1,HeightData)
axis([1,21,1,21,0,2000])
hold on
k=1:21;
plot3(k(1),a(1,1),a(1,2)*200,'--o',...
                       'MarkerFaceColor','g',...
                       'MarkerSize',10)
plot3(k(21),a(21,1),a(21,2)*200,'--o',...
                       'MarkerFaceColor','g',...
                       'MarkerSize',10)
text(k(1)+1,a(1,1)+1,a(1,2)*200+10,'S');   %标注起点何种顶
text(k(21)+1,a(21,1)+1,a(21,2)*200+10,'T');
xlabel('km','fontsize',12);
ylabel('km','fontsize',12);
zlabel('m','fontsize',12);
title('Matlab蚁群算法三维避障','fontsize',12)
%set(gcf, 'Renderer', 'ZBuffer')
hold on
plot3(k,a(:,1),a(:,2)*200,'--ro')

%% 适应度变化
figure(2)
plot(BestFitness)
title('最佳个体适应度变化趋势')
xlabel('迭代次数')
ylabel('适应度值')
