#include<iostream>
using namespace std;
int main()
{
	int i,sum;
	i=1,sum=0;
	while(i<=99)
	{
		sum=sum+i;
		i=i+2;
	}
	cout<<"sum="<<sum<<endl;
	return 0;
}
