#include<iostream>
using namespace std;
int main()
{
	int a[8];
	for(int i=0;i<8;i++)
	{
		int x;
		cin>>x;
		a[i]=x;
	}
	int max=a[0];
	for(int i=1;i<8;i++)
	{
		int y=a[i];
		max=max>y?max:y;
	}
	cout<<max<<endl;
	for(int i=0;i<8;i++)
	{
		int y=a[i];
		if(y==max)cout<<i<<" ";continue;
	}
}
