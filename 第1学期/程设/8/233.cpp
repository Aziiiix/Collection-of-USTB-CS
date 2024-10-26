#include<bits/stdc++.h>
using namespace std;
int main()
{
 int y,N,i0,i;
 cin>>y>>N;
 if((y%4==0&&y%100!=0)||(y%400==0))
 {
  i0=2;
  } 
  else
  {
   i0=1;
  }
 for(i=i0;i<=N;++y)
 {
  if((y%4==0&&y%100!=0)||(y%400==0))
  {
   i++;
  }
 }
 cout<<y-1<<endl;
 return 0;
}
