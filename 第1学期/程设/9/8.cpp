#include<iostream>
using namespace std;
int f(int n)
{
	int sum=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		int a,b,c,d,e,f;
		a=x/100;
		if(a!=0)
		b=x%(a*100)/50;
		else b=x/50;
		if(a!=0||b!=0)
		c=x%(a*100+b*50)/10;
		else c=x/10;
		if(a!=0||b!=0||c!=0)
		d=x%(a*100+b*50+c*10)/5;
		else d=x/5;
		if(a!=0||b!=0||c!=0||d!=0)
		e=x%(a*100+b*50+c*10+d*5)/2;
		else e=x/2;
		if(a!=0||b!=0||c!=0||d!=0||e!=0)
		f=x%(a*100+b*50+c*10+d*5+e*2);
		else f=x;
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
