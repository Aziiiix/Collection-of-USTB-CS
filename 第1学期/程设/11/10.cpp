//code by handsome Aziiii
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int** p;
	p = new int* [n];//���嶯̬��ά����
	for (int i = 0;i < n;i++)
	{
		p[i] = new int[n];
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			p[i][j] = 0;
		}
	}//��ʼ����ά����Ϊ0
	int num = 1;//��ʼ����ʼ����1
	int x= 0,y=n;//��ʼ����������
	while(x<=y)
	{
	for (int i = x,j = y-1;i < y;i++)
	{
		if(p[i][j]==0){
		p[i][j] = num;
		num++;}
		else break;
	}
	for (int i = y-1,j = y - 2;j >= 0;j--)
	{
		if(p[i][j]==0){
		p[i][j] = num;
		num++;}
		else break;
	}
	for (int i = y - 2,j = x;i >= 0;i--)
	{
		if(p[i][j]==0){
		p[i][j] = num;
		num++;}
		else break;
	}
	for (int i = x,j = x+1;j <y-1;j++)
	{
		if(p[i][j]==0){
		p[i][j] = num;
		num++;}
		else break;
	}
	++x;--y;
    }
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (j == n - 1)
			{
				if(p[i][j]<10){
				cout<<"   "<<p[i][j]<<endl;}
				if(p[i][j]>=10&&p[i][j]<100){
				cout<<"  "<<p[i][j]<<endl;}
				if(p[i][j]>=100){
				cout<<" "<<p[i][j]<<endl;}
			}
			else 
			{
				if(p[i][j]<10){
				cout <<"   "<< p[i][j];}
				if(p[i][j]>=10&&p[i][j]<100){
				cout<<"  "<<p[i][j];}
				if(p[i][j]>=100){
				cout<<" "<<p[i][j];}
			}
		}
	}//���������ֵ
	return 0; 
}
