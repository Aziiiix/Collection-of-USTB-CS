#include<iostream>
using namespace std;
void f(int a)
{
	int t=0,b=0;
	while (a!=0)
	{
		t=a%10;
		b=b*10+t;
		a=a/10;
	}
	cout<<b<<endl;
}
int main()
{
	int number;
	cin>>number;
	f(number);
	return 0;
}
