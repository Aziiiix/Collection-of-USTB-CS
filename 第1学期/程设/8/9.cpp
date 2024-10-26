#include<iostream>
#include<cmath>
using namespace std;
int main()
{int a,b,c,d;
cin>>a;
c=0,d=0;
do
{ b=a%10;
c=c+b*pow(8,d);
a=a/10;
d=d+1;
}while(a>0);
cout<<c<<endl;
}
