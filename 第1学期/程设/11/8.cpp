#include<iostream>
using namespace std;
int main()
{
	int a[10]={1,3,5,7,9,11,13,15,17,19};
	int num;
	cin>>num;
	for(int i=0;i<10;i++)
	{
		if(num==a[i])
		{
			cout<<"yes";
			return 0;
		}
		else continue;
	}
	cout<<"no";
	return 0;
}
