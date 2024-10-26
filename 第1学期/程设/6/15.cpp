#include<iostream>
using namespace std;
int main()
{
	int y,m,d;
	cin>>y>>m>>d;
	if(y%4==0&&y%100!=0||y%400==0)
	{
		if(m==2&&d==29)cout<<"-1";
		else cout<<18*365+4;
	}
	else cout<<18*365+4;
 } 
