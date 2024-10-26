#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a<16)cout<<"Iam a child!"<<endl;
	else if(a>=16&&a<=55)cout<<"I am an adult!"<<endl;
	else if(a>55)cout<<"I am an old!"<<endl; 
	return 0;
}
