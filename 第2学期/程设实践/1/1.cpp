#include<iostream>
using namespace std;
int main()
{
	char*str=new char [16];
	cin>>str;
	if(str[0]=='1')
	{
		for(int i=1;i<16;i++)
		{
			if(str[i]=='0')str[i]='1';
			else str[i]='0';
		}
	}
	int num=0;
	for(int i=1;i<16;i++)
	{
		num=num*2+str[i]-48;
	}
	if(str[0]=='0')
	{
		cout<<num;
	}
	if(str[0]=='1')
	{
		cout<<num*(-1)-1;
	}
	return 0;
}
