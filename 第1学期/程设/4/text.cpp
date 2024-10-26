#include<iostream>
using namespace std;
int main()
{
   int x;
   cin>>x;
   int a,b,c,d,e;
   if(x>99999)cout<<"a bad number"<<endl;
   else
   {
   	a=x/10000;
   	b=(x/1000)%(a*10);
   	c=(x/100)%(a*100+b*10);
   	d=(x/10)%(a*1000+b*100+c*10);
   	e=x%(a*10000+b*1000+c*100+d*10);
   	cout<<"10000:"<<a<<" 1000:"<<b<<" 100:"<<c<<" 10:"<<d<<" 1:"<<e; 
   }
   return 0;
}
