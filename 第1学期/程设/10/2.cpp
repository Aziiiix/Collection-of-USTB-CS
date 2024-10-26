#include<iostream>
using namespace std;
int main()
{
	char*a=new char[10001];
	char*b=new char[10001];
	cin>>a;
	int i=0;
	for(int j=0;i<10001;i++)
	{
		if(a[i]!='T')
		{
			b[j]=a[i];
			j++;
		}
		else continue;
	}
	cout<<b<<endl;
	delete[]a;
	delete[]b;
	a=0;b=0;
	return 0;
}
