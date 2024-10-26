#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	switch(a)
	{
		case 1:cout<<12.5*b;break;
		case 2:cout<<20.5*b;break;
		case 3:cout<<10.4*b;break;
		case 4:cout<<17.5*b;break;
		default:cout<<"error";
	}
	return 0;
}
