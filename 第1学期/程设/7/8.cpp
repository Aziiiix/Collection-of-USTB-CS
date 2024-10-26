#include<iostream>
using namespace std;
void Move(int n,char a,char b,char c)
{
	if(n==1)cout<<a<<" to "<<c<<endl;
	else
	{
		Move(n-1,a,c,b);
		cout<<a<<" to "<<c<<endl;
		Move(n-1,b,a,c);
	}
}
int main()
{
	int m;
	cin>>m;
	Move(m,'A','B','C');
}
