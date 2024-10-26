#include<iostream>
using namespace std;
int main()
{
	int a,b,x,y;
	cin>>a>>b;
	x=(4*a-b)/2;//每只兔子多两条腿
	y=a-x;
	cout<<"rabbit="<<y<<",chicken="<<x<<endl;
	return 0;

}
