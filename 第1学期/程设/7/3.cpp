#include<iostream>
using namespace std;
int main()
{
	int a,b=0;
	cin>>a;
	while(a!=b){
		b=a%2;
		cout<<b;
		a=a/2;
	}
	return 0;
 } 
