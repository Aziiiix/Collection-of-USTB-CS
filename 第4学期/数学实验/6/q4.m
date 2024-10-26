fun=inline('4./(1+x.*x)');

data=[];
counter=1;

for n=1:1000:100000
    x=unifrnd(0,1,n,1);
    y=mean(fun(x));
    data(counter)=pi-y;
    counter=counter+1;
end

a=1:1000:100000;
plot(a,data,'g.');
ylim([-0.1 0.1]);