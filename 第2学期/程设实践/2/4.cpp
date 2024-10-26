#include<iostream>
using namespace std;

void move(int *arry,int n,int m)
{
	//there is nothing
}

int main()
{
	int a[10];
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	for(int i=7;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	for(int i=0;i<7;i++)
	{
		if(i<6)
		{
			cout<<a[i]<<" ";
		}
		if(i==6)
		{
			cout<<a[i];
		}
	}
	
	return 0;
 } 
