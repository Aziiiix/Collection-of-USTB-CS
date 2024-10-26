#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char s[100];
	cin.get(s,100);
	char* p=new char [100];
	p[1]=s[1];
	cout<<p[1];
}
