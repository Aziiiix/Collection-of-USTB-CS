//CODE BY AZIIII
#include<iostream>
#include<cmath>
using namespace std;

double cal1(double num)
{
	double s1 = exp(num);
	double s2 = 9 * num * num;
	double s3 = 4 * num;
	double s4 = 1/num;
	return s1 + s2 + s3 + s4;
}
//���μ���f'(x) 

double cal2(double num)
{
	double s1 = exp(num);
	double s2 = 3 * num * num * num;
	double s3 = 2 * num * num;
	double s4 = log(num);
	return s1 + s2 + s3 + s4 - 1;
}
//���μ���f(x) 

int main()
{
	double a = 0, b = 1;
	double ans = 0;
	bool check = true;//ѭ���жϱ�׼ 
	while (check)
	{
		double c = b - cal2(b)/cal1(b);
		if (abs(c - b) < 0.0001)//���С��0.0001ʱ�õ��� 
		{
			ans = c;
			check = false;//����ѭ�� 
		}
		else//������ 0.0001ʱ����ѭ�� 
		{
			b = c;
			cout<<"b:"<<b<<endl;
		}
	}
	cout << ans << endl;
	
	return 0;
}
