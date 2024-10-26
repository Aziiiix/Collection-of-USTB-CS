function [path,pheromone]=searchpath(PopNumber,LevelGrid,PortGrid,pheromone,HeightData,starty,starth,endy,endh)
%% 该函数用于蚂蚁蚁群算法的路径规划
%PopNumber   种群个数
%LevelGrid     input    横向划分格数
%PortGrid      input    纵向划分个数
%pheromone     input    信息素
%HeightData    input    地图高度
%starty starth input    开始点
%path          output   规划路径
%pheromone     output   信息素

%% 搜索参数
ycMax=2;   %蚂蚁横向最大变动
hcMax=2;   %蚂蚁纵向最大变动
decr=0.9;  %信息素衰减概率

%% 循环搜索路径
for ii=1:PopNumber
    
    path(ii,1:2)=[starty,starth];  %记录路径
    NowPoint=[starty,starth];      %当前坐标点
    
    %% 计算点适应度值
    for abscissa=2:PortGrid-1
        %计算所有数据点对应的适应度值
        kk=1;
        for i=-ycMax:ycMax   % y横向变动，步长-2：2
            for j=-hcMax:hcMax   %先高度移动-2，-1,0,1,2
                NextPoint(kk,:)=[NowPoint(1)+i,NowPoint(2)+j];
                if (NextPoint(kk,1)<20)&&(NextPoint(kk,1)>0)&&(NextPoint(kk,2)<20)&&(NextPoint(kk,2)>0)
                    %判断下个点是否在（0，20）范围之内，利用下一个点的横纵坐标
                    qfz(kk)=CacuQfz(NextPoint(kk,1),NextPoint(kk,2),NowPoint(1),NowPoint(2),endy,endh,abscissa,HeightData);
                    %启发值计算
                    qz(kk)=qfz(kk)*pheromone(abscissa,NextPoint(kk,1),NextPoint(kk,2)); 
                    %乘以相应的信息素系数,即pheromore(x,y,z)，初始值都是1
                    kk=kk+1;
                else
                    qz(kk)=0;
                    kk=kk+1;
                end
            end
        end
       %{两个for循环先遍历保持横坐标x不变的平面上的所有点，共5x5=25个点} 
       
  %%   这里是原程序的轮盘赌方法  
        %选择下个点
      %  sumq=qz./sum(qz);
    
      %  pick=rand;   %指针，如果为零就一直再选，轮盘赌
      %  while pick==0
      %      pick=rand;
      %  end
        
      %  for i=1:25   
        %    pick=pick-sumq(i);
       %     if pick<=0 %找到第一个累加小于指针的索引，0无影响
        %        index=i;
       %         break;
       %     end
       % end
 %----------------------------更为简单的方式
          P = qz/sum(qz);
             % 轮盘赌法选择下一个访问城市
          Pc = cumsum(P);     %累加函数，把前几个累加到1
          target_index = find(Pc >= rand);
          index = target_index(1);

 %%
        oldpoint=NextPoint(index,:);
        
        %更新信息素，注意这里的横坐标加一
        pheromone(abscissa+1,oldpoint(1),oldpoint(2))=0.5*pheromone(abscissa+1,oldpoint(1),oldpoint(2));
        
        %路径保存，两个两个往后推
        path(ii,abscissa*2-1:abscissa*2)=[oldpoint(1),oldpoint(2)];    
        NowPoint=oldpoint;
        
    end
    path(ii,41:42)=[endy,endh];
    %21*2-1=41，21*2=42
end