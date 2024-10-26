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
//单次代入公式计算结果 

int main()
{
	
	double a = 0, b = 1;
	//区间[0,1] 
	double ans = 0;
	//答案初始化 
	double stand0 = -1, stand1 = cal(1);
	//首先求出两区间值 
	while (abs(stand0 - stand1) > 10 ^ (-4))//两次计算结果大于误差 
	{
		ans = (a + b) / 2;//二分法求中值 
		if (cal(ans) == 0)//等于0则直接求出 
		{
			cout << ans << endl;
			return 0;
		}
		else
		{//重新判断区间 
			if (cal(ans) * cal(a) < 0) 
			{
				a = a;
				b = ans;
				stand0 = cal(a);
				stand1 = cal(ans);//更新比较标准 
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
	cout << ans << endl;//输出结果 
	
	return 0;
}
