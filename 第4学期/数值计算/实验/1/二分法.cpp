//CODE BY AZIIII
#include<iostream>
#include<cmath>
using namespace std;

double cal(double num)
{
	double s1 = exp(num);
	double s2 = 3 * num * num * num;
	double s3 = 2 * num * num;
	double s4 = log(num);
	return s1 + s2 + s3 + s4 - 1;
}
//���δ��빫ʽ������ 

int main()
{
	
	double a = 0, b = 1;
	//����[0,1] 
	double ans = 0;
	//�𰸳�ʼ�� 
	double stand0 = -1, stand1 = cal(1);
	//�������������ֵ 
	while (abs(stand0 - stand1) > 10 ^ (-4))//���μ������������ 
	{
		ans = (a + b) / 2;//���ַ�����ֵ 
		if (cal(ans) == 0)//����0��ֱ����� 
		{
			cout << ans << endl;
			return 0;
		}
		else
		{//�����ж����� 
			if (cal(ans) * cal(a) < 0) 
			{
				a = a;
				b = ans;
				stand0 = cal(a);
				stand1 = cal(ans);//���±Ƚϱ�׼ 
				cout<<"a:"<<a<<" b:"<<b<<endl;
			}
			if (cal(ans) * cal(b) < 0)
			{
				b = b;
				a = ans;
				stand0 = cal(ans);
				stand1 = cal(b);
				cout<<"a:"<<a<<" b:"<<b<<endl;
			}
		}
	}
	cout << ans << endl;//������ 
	
	return 0;
}
