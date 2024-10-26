#include<iostream>
using namespace std;
int main()
{
	char a,b,c;
	cin>>a>>b>>c;
	char x;
	if(a>b)x=a,a=b,b=x;
	if(b>c)x=b,b=c,c=x;
	if(a>b)x=a,a=b,b=x;
	cout<<a<<" "<<b<<" "<<c;
	return 0;
}
