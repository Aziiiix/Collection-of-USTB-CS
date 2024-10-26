#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	if(x<0)cout<<"illegal input"<<endl;
	else if(x<5&&x>=0)cout<<x<<endl;
	else if(x>=5&&x<15)cout<<x+6<<endl;
	else if(x>=15)cout<<x-6<<endl;
	return 0;
}
