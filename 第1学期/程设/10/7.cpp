//code by Aziiii
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char*a=new char[201];
	char*b=new char[201];
	cin>>a;
	cin>>b;
	strcat(a,b);
	cout<<a<<endl;
	delete[]a;
	delete[]b;
	a=0;b=0;
	return 0;
}
