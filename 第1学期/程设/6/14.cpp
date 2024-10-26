#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c,d,e,f,m;
	cin>>a>>b>>c>>d>>e>>f;
	m=(a>b?a:b);
	m=(m>c?m:c);
	m=(m>d?m:d);
	m=(m>e?m:e);
	m=(m>f?m:f);
	cout<<m<<endl;
	return 0; 
 } 
