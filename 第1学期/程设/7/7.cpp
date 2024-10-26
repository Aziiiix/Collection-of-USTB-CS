#include<iostream>
#include<cmath> 
using namespace std;
int prime(int m)
{
 int t=1;
 for(int i=2;i<=sqrt(m);i++)
 if(m%i==0)
 t=0;
 if(t==1)
 return 1;
 else
 return 0;
}
int main()
{
 int n;
 cin>>n;
 for(int i=2;i<=n/2;i++)
 if(prime(i)&&prime(n-i))
 cout<<n-i<<" "<<"+"<<" "<<i<<" "<<"="<<n<<endl;
 return 0; 
}
