clc
clf

subplot(221)
a=1:30;
u=unidrnd(365,1,30);
plot(a,u,'b.');
title('模拟1个班');
hold on;
for i=1:29
    for j=i+1:30
        if u(i)==u(j)
            subplot(221)
            plot(i,u(i),'r*',j,u(j),'r*',[i,j],[u(i),u(j)],'r');
        end
    end
end

subplot(222)
for num=1:100
    
    a=1:30;
    y=0;
    u=unidrnd(365,1,30);
    hold on,plot(num,u,'b.')
    ylim([0 370]);
    title('模拟100个班');

    for i=1:29
        for j=i+1:30
            if u(i)==u(j)
            y=y+1;
            plot(num,u,'b.',num,u(i),'r*',num,u(j),'r*')
            end
        end
    end

end

subplot('Position',[0.2,0.05,0.6,0.45])

rate=[];
for counter=1:100
    y=0;
    for num=1:counter
        check=0;
        u=unidrnd(365,1,30);

        for i=1:29
            for j=i+1:30
                if u(i)==u(j)
                    y=y+1;
                    check=1;
                    break;
                end
            end
            if check==1
                break;
            end
        end
    end
    s=y/counter;
    rate(counter)=s;
end

a=1:100;
b=1;
plot(a,rate,'g.');
hold on;
y=0.7063;
x=0:1:100;
plot(x,y,'r_')

title('频率随n渐增变化')
