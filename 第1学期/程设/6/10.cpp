#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b>c&&a+c>b&&b+c>a)
	{
		if(a==b||a==c||b==c)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	else cout<<"not a triangle"<<endl;
	return 0;
 } 
