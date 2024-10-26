#include<iostream>
using namespace std;
int main()
{
	char*a=new char[10];
	char*b=new char[10];
	cin>>a>>b;
	int ans[10];
	for(int i=0;i<10;i++)
	{
		ans[0]=a[0]-'0';
	}
	cout<<ans[0];
}
