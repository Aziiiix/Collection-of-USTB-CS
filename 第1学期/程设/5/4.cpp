#include<iostream>
using namespace std;
int main()
{
   int x;
   cin>>x;
   int a,b,c,d,e,f,g,h,i,j,k,l,m,n;
   if(x>99999)cout<<"a bad number"<<endl;
   else if(x>9999){
   	a=x/10000;
   	b=(x/1000)%(a*10);
   	c=(x/100)%(a*100+b*10);
   	d=(x/10)%(a*1000+b*100+c*10);
   	e=x%(a*10000+b*1000+c*100+d*10);
   	cout<<"10000:"<<a<<" 1000:"<<b<<" 100:"<<c<<" 10:"<<d<<" 1:"<<e; }
   		else if(x>999){
   		f=x/1000;
   		g=(x/100)%(f*10);
   		h=(x/10)%(f*100+g*10);
   		i=x%(f*1000+g*100+h*10);
   	    cout<<"1000:"<<f<<" 100:"<<g<<" 10:"<<h<<" 1:"<<i;}
	    else if(x>99){
   		j=x/100;
   		k=x/10%(j*10);
   		l=x%(j*100+k*10);
   		cout<<"100:"<<j<<" 10:"<<k<<" 1:"<<l;}
   		else if(x>9){
   		m=x/10;
   		n=x%(m*10);
   		cout<< "10:"<<m<<" 1:"<<n;}
   		else if(x>0){
		cout<<"1:"<<x;}
}
