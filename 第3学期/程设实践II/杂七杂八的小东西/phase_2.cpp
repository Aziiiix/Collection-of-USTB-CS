#include<iostream>
using namespace std;
int main()
{
	int a[9]={0};
	a[0]=9;a[1]=18;
	
	for(int i=2;i<9;i++)
	{
		a[i]=a[i-1]+(a[i-2]/2);
	}
	
	for(int i=0;i<9;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
 } 
