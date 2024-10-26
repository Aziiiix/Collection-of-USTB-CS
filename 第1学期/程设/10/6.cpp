#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	char str[10001];
	cin.getline(str,10001);
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]>=65&&str[i]<=90)
		{
			cout<<char(str[i]+3);
			continue;
		}
		if(str[i]>=97&&str[i]<=122)
		{
			cout<<char(str[i]+3);
			continue;
		}
		else cout<<str[i];
	}
	return 0;
 } 
