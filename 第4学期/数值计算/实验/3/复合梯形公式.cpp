//CODE BY AZIIII
#include<iostream>
#include<cmath>
using namespace std;

//���f(x)��ֵ 
double function(double x) {
	long double x1, x2, x3, x4;
	x1 = 2 * x - x * x + x * x * x;
	x2 = exp(x / 2);
	x3 = x1 + x2;
	x4 = pow(0.5, x3);
	return x4;
}

//�������ι�ʽ���� 
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

//�����ض�����Ͳ����������μ���ֵ 
double fun_T(double n){
	int a=2,b=0;
	double T = Trapezoid(a,b,n);
	return T;
}

int main()
{
	double T1=fun_T(1);//��ʼ��n=1ʱ�����μ���ֵ 
	for(int i=2;i<100;i++)
	{
		double T2=fun_T(i);//����n=iʱ�����μ���ֵ
		if(abs(T2-T1)<0.00001)//�Ƚ�����Ƿ�С��0.00001 
		{
			cout<<i<<endl;
			cout<<"ans:"<<T2<<endl;
			break;
			//С��0.00001ʱ�������������������μ���ֵ 
		}
		else
		{
			cout<<i<<" "<<T2<<endl;
			T1=T2;
			//��С��0.00001ʱ���±Ƚ�ֵ��������˴μ���ֵ 
		}
		
	}
	
	return 0;
}
