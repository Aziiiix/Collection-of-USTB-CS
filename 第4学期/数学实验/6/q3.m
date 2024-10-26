y=[];
for N=1:1000
    Test=randi([1,6],N,1);
    M=length(find(Test==5));
    y(N)=M/N;
    fprintf('N=%d时，掷骰子5朝上的次数是%d，频率是%f\n',N,M,M/N)
end

a=1:1:1000;
plot(a,y,'g.');
hold on
b=0.166667;
plot(a,b,'r_');