#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int num;
	cin>>num;
	if(num==0||num==1)
	{
		cout<<"N";return 0;
	}
	int st;
	st=sqrt(num);
	for(int i=2;i<st;i++)
	{
		if(num%i==0)
		{
			cout<<"N"<<endl;
			return 0;
		}
	}
	cout<<"Y"<<endl;
	return 0;
}
