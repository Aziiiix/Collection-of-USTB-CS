#include<iostream>
using namespace std;
int main()
{int y,n,m=0;
cin>>y>>n;
for(y;;y++)
{if(y%4==0&&y%100!=0||y%400==0) m+=1;
else m=m;
if(m==n) break;
}
cout<<y<<endl;
}

