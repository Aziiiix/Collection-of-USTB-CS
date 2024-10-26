#include<iostream>
using namespace std;
int main()
{
	int x,a,b,c,d,A,B,C,D,m,n;
	cin>>x;
	a=x/1000;
	b=(x/100)%(a*10);
	c=(x/10)%(a*100+b*10);
	d=x%(a*1000+b*100+c*10);
	A=(a+9)%10;
	B=(b+9)%10;
	C=(c+9)%10;
	D=(d+9)%10;
	m=A,A=C,C=m;
	n=B,B=D,D=n;
	cout<<A*1000+B*100+C*10+D<<endl;
	return 0;
}
