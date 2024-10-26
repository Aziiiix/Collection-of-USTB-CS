#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char str[10000];
	cin.getline(str,10000);
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i]=='R'&&str[i+1]=='e'&&str[i+2]=='d')
		{
			cout<<"Red ";
			continue;
		}
	 } 
	 for(int i=0;i<len;i++)
	{
		if(str[i]=='B'&&str[i+1]=='l'&&str[i+2]=='u'&&str[i+3]=='e')
		{
			cout<<"Blue ";
			continue;
		}
	 } 
	 for(int i=0;i<len;i++)
	{
		if(str[i]=='W'&&str[i+1]=='h'&&str[i+2]=='i'&&str[i+3]=='t'&&str[i+4]=='e')
		{
			cout<<"White ";
			continue;
		}
	 } 
	 return 0;
}
