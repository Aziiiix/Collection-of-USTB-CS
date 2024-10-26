#include<iostream>
using namespace std;
int main()
{
	int x=1;
	for(x=1;x<3122;x++)
	{
		int a,b,c,d;
		a=((x-1)/5)*4;
		b=((a-1)/5)*4;
		c=((b-1)/5)*4;
		d=((c-1)/5)*4;
		if((x-1)%5==0&&((a-1)%5==0)&&((b-1)%5==0)&&((c-1)%5==0)&&((d-1)%5==0))cout<<x<<endl;
	}
	return 0;
 } 
