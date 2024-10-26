#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	char str[50];
	cin.getline(str,50);
	int count=0;
	int size=strlen(str);
	for(int i=0;i<size;i++)
	{
		if(str[i]=='b'&&str[i+1]=='d')
		{
			count++;continue;
		}
	}
	cout<<count<<endl;
	return 0;
 } 
