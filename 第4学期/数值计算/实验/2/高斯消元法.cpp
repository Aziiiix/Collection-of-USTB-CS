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
		//����ÿ����Ԫ��ϵ��
		
		for(int j=i+1;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				a[j][k]=a[j][k]-c[j]*a[i][k];
				//a������Ԫ 
			 } 
			 b[j]=b[j]-c[j]*b[i];
			 //bֻ��Ԫһ�� 
		 } 
	}
	
	double x[n];
	//�洢x�Ľ� 
	x[n-1]=b[n-1]/a[n-1][n-1];
	//�����һ��δ֪����ʼ��� 
	for(int i=n-2;i>=0;i--)
	{
		double sum=0;
		for(int j=i+1;j<n;j++)
		{
			sum+=a[i][j]*x[j];
			//����֪���������һ���� 
		}
		x[i]=(b[i]-sum)/a[i][i];
		//��β��ͷ������� 
	}
	
	for(int i=0;i<n;i++)
	{
		cout << "x" << i + 1 << "=" << setprecision(5) << x[i] << endl;
	}
	//�������x�Ľ� 
}


int main()
{
	double a[4][4] = { 14,2,1,5,8,17,2,10,4,18,3,6,12,26,11,20 };
    double b[4] = { 1,2,3,4 };
    //�������� 
    gus(a, b);
    //��˹��Ԫ������ 
    return 0;
}
