#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int seed,b,c,m;
	cin>>seed>>b>>c>>m;
	cout<<"a0"<<"  "<<seed<<endl;
	int a0=seed;
	cout<<"a1"<<setw(2)<<(b*a0+c)%m<<endl;
	int a1=(b*a0+c)%m;
	cout<<"a2"<<setw(2)<<(b*a1+c)%m<<endl;
	int a2=(b*a1+c)%m;
	cout<<"a3"<<setw(2)<<(b*a2+c)%m<<endl;
	int a3=(b*a2+c)%m;
	cout<<"a4"<<setw(2)<<(b*a3+c)%m<<endl;
	return 0;
}
