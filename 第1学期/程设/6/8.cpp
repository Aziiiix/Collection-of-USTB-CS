#include<iostream>
using namespace std;
int main()
{
	int x,a,b,c,d,e;
	cin>>x;
	a=x/10000;
	b=(x/1000)%(a*10);
	c=(x/100)%(a*100+b*10);
	d=(x/10)%(a*1000+b*100+c*10);
	e=x%(a*10000+b*1000+c*100+d*10);
	if(a==e&&b==d)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
 } 
