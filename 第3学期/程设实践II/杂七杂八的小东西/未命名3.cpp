#include<iostream>
using namespace std;
int main()
{
	int*a=new int[3];
	for(int i=0;i<3;i++)
	{
		a[i]=i;
	}
	for(int i=0;i<3;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
