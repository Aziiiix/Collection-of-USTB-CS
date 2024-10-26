//CODE BY AZIIII
#include<iostream>
#include<cmath>
using namespace std;

//求出f(x)的值 
double function(double x) {
	long double x1, x2, x3, x4;
	x1 = 2 * x - x * x + x * x * x;
	x2 = exp(x / 2);
	x3 = x1 + x2;
	x4 = pow(0.5, x3);
	return x4;
}

//复合梯形公式计算 
double Trapezoid(double a,double b,double n)
{
	double h = (a - b) / n;
	double T, temp = 0;
	for (int i = 1; i <= n - 1; i++){
		double x = b + i * h;
		temp += function(x);
	}
	T = (h / 2) * (function(a) + 2 * temp + function(b));
	return T;
}

//根据特定区间和步数计算梯形计算值 
double fun_T(double n){
	int a=2,b=0;
	double T = Trapezoid(a,b,n);
	return T;
}

int main()
{
	double T1=fun_T(1);//初始化n=1时的梯形计算值 
	for(int i=2;i<100;i++)
	{
		double T2=fun_T(i);//计算n=i时的梯形计算值
		if(abs(T2-T1)<0.00001)//比较误差是否小于0.00001 
		{
			cout<<i<<endl;
			cout<<"ans:"<<T2<<endl;
			break;
			//小于0.00001时输出答案字样并输出该梯形计算值 
		}
		else
		{
			cout<<i<<" "<<T2<<endl;
			T1=T2;
			//不小于0.00001时更新比较值，并输出此次计算值 
		}
		
	}
	
	return 0;
}
