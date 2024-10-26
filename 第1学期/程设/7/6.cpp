#include<iostream>
using namespace std;
int main()
{
   int n,i=1,s=0;
   cin>>n;
   while(i<=n){
   	s=s+i*i*i;
   	i++;
   }
 cout<<s;
 return 0;
}
