#include<iostream>
using namespace std;
int main() 
{
	int x,y,p,q,a,b,c,d;
	cin>>x;
	cin>>y;
	p=(x/100)*60+x%100;
	q=(y/100)*60+y%100;
	a=q-p;
	b=a/60;
	c=a%60;
	cout<<b<<" hrs "<<c<<" mins "<<endl;
	
}
