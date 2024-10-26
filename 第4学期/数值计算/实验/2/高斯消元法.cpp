//CODE BY AZIIII
#include<iostream>
#include<iomanip>
using namespace std;

const int n=4;
void gus(double a[n][n],double b[n])
{
	double c[n];
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			c[j]=a[j][i]/a[i][i];
		}
		//计算每次消元的系数
		
		for(int j=i+1;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				a[j][k]=a[j][k]-c[j]*a[i][k];
				//a依次消元 
			 } 
			 b[j]=b[j]-c[j]*b[i];
			 //b只消元一次 
		 } 
	}
	
	double x[n];
	//存储x的解 
	x[n-1]=b[n-1]/a[n-1][n-1];
	//从最后一个未知数开始求解 
	for(int i=n-2;i>=0;i--)
	{
		double sum=0;
		for(int j=i+1;j<n;j++)
		{
			sum+=a[i][j]*x[j];
			//将已知解代入求下一个解 
		}
		x[i]=(b[i]-sum)/a[i][i];
		//从尾到头依次求解 
	}
	
	for(int i=0;i<n;i++)
	{
		cout << "x" << i + 1 << "=" << setprecision(5) << x[i] << endl;
	}
	//依次输出x的解 
}


int main()
{
	double a[4][4] = { 14,2,1,5,8,17,2,10,4,18,3,6,12,26,11,20 };
    double b[4] = { 1,2,3,4 };
    //输入数组 
    gus(a, b);
    //高斯消元法计算 
    return 0;
}
