//code by Aziiii
#include<iostream>
#include<cstring> 
using namespace std;
int main()
{
	char str[80];
	cin >> str;
	int i , j, len;
	len = strlen(str);
	int check=1;
	for (i = 1; i <= len; i++)//i为周期串长度
	{
		if (len % i == 0)
		{
			for (j = i; j < len; j++)
			{
				if (str[j] != str[j % i])
				{
					check = 0;
					break;
			}
			}
			if(check){
				cout<<i<<endl;break;
			}
		}
	}
	return 0;
}
