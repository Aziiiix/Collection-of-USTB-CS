//CODE BY AZIIII
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

template<class T>
void jh(T& a, T& b)
{
	T c; c = b; b = a; a = c;
}
//设置函数便于交换行 

const int n = 4;
void lgus(double a[n][n], double b[n])
{
	int col, row;
	for (int i = 0; i < n - 1; i++)
	{
		double max = 0;
		for (int j = i; j < n; j++)
		{
			if (fabs(a[j][i]) > max)
			{
				max = fabs(a[j][i]);
				col = i; row = j;
			}
		}
		//寻找最大主元
		
		if (i != row)
		{
			for (int j = 0; j < n; j++)
			{
				jh(a[row][j], a[i][j]);
			}
			jh(b[row], b[i]);
		}
		//交换最大主元所在行 
		
		//回归高斯消元法 
		double c[n];
		for (int j = i + 1; j < n; j++)
		{
			c[j] = a[j][i] / a[i][i];
		}
		//求出每次消元系数 
		
		for (int j = i + 1; j < n; j++)
		{
			for (int k = 1; k < n; k++)
			{
				a[j][k] = a[j][k] - c[j] * a[i][k];
			}
			b[j] = b[j] - c[j] * b[i];
			//依次消元 
		}
	}

	double x[n];
	x[n - 1] = b[n - 1] / a[n - 1][n - 1];
	//计算最后一解 
	
	for (int j = n - 2; j >= 0; j--)
	{
		double sum = 0;
		for (int k = j + 1; k < n; k++)
		{
			sum += a[j][k] * x[j];
		}
		x[j] = (b[j] - sum) / a[j][j];
		//依次代入已知解并解出下一解 
	}
	
	for (int j = 0; j < n; j++)
	{
		cout << "x" << j + 1 << "=" << setprecision(5) << x[j] << endl;
	}
	//输出答案 
	
}

int main()
{
	double a[4][4] = { 14,2,1,5,8,17,2,10,4,18,3,6,12,26,11,20};
	double b[4] = { 1,2,3,4 };
	//输入数组 
	lgus(a, b);
	//列主消元法 
	return 0;
}
