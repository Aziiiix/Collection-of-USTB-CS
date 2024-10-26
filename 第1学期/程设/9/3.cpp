#include<iostream>
using namespace std;
f(int n)
{
	int sum=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		int a,b,c,d,e,f;
		a=x/100;
		b=(x%100)/50;
		c=x%(a*100+b*50)/10;
		d=x%(a*100+b*50+c*10)/5;
		e=x%(a*100+b*50+c*10+d*5)/2;
		f=x%(a*100+b*50+c*10+d*5+e*2);
		sum=sum+a+b+c+d+e+f;
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
}
