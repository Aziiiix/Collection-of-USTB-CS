#include<iostream>
using namespace std;
int main()
{
	char*a=new char[10001];
	cin>>a;
	for(int i=0;i<10001;i++)
	{
		if(a[i]>=65&&a[i]<=90)
		{
			a[i]=a[i]+32;
		}
		if(a[i]>=97&&a[i]<=122)
		{
			a[i]=a[i]-32;
		}
	}
	cout<<a<<endl;
	delete[]a;
	a=0;
	return 0;
}
