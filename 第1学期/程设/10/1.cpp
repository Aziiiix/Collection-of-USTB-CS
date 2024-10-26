//code by Aziiii
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char*a=new char[100];
	char*b=new char[100];
	cin>>a>>b;
	int compare;
	compare=strcmp(a,b);
	if(!compare)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	delete[]a;
	delete[]b;
	a=0;b=0;
	return 0;
}
