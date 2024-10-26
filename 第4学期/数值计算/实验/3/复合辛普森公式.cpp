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

//复合辛普森公式计算 
double Simpson(double a,double b,double n)
{
	int m = n / 2;
	int i;
	double h = (a - b) / n;
	double S = 0;
	for (i = 1; i <= m - 1; i++){
		double x = b + 2 * i * h;
		S += function(x);
	}
	double temp = 0;
	for (i = 1; i <= m; i++){
		double x = b + (2 * i - 1) * h;
		temp = temp + function(x);
	}
	S = (h / 3) * (function(a) + 2 * S + 4 * temp + function(b));
	return S;
}

//根据特定区间和步数计算辛普森计算值 
double fun_S(double n){
	int a=2,b=0;
	double S = Simpson(a,b,n);
	return S;
}

int main()
{
	double S1=fun_S(1);//初始化n=1时的辛普森计算值 
	for(int i=2;i<150;i++)
	{
		double S2=fun_S(i);//计算n=i时的辛普森计算值 
		if(abs(S2-S1)<0.00001)//比较误差是否小于0.00001 
		{
			cout<<i<<endl;
			cout<<"ans:"<<S2<<endl;
			break;
			//小于0.00001时输出答案字样并输出该辛普森计算值 
		}
		else
		{
			cout<<i<<" "<<S2<<endl;
			S1=S2;
			//不小于0.00001时更新比较值，并输出此次计算值 
		}
		
	}
	
	return 0;
}
