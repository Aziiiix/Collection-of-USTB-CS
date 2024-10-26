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
	else if((y+2)&4==0&&(y+2)%100!=0||(y+2)%400==0)cout<<18*365+5;
	else if((y+1)&4==0&&(y+1)%100!=0||(y+1)%400==0)cout<<18*365+5;
	else cout<<18*365+4;
 } 

