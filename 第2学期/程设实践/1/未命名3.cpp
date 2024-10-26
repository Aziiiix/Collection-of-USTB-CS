#include<iostream>
using namespace std;
int main()
{
	int x=10,y=20,z=30;
	if(x>y)
	z=x;x=y;y=z;
	cout<<x<<" "<<y<<" "<<z<<endl;
	return 0;
 } 
