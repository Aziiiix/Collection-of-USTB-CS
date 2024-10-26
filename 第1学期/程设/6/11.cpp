#include<iostream>
using namespace std;
int main()
{
	float r1,i1,r2,i2;
	char op;
	cin>>r1>>i1>>op>>r2>>i2;
	switch(op)
	{
		case '+':cout<<r1+r2<<op<<i1+i2<<"i";break;
		case '-':cout<<r1-r2<<op<<i1-i2<<"i";break;
		case '*':cout<<r1*r2<<op<<i1*i2<<"i";break;
		case '/':{
			if(r2=00&&i2==0)cout<<"Divisor cannot be 0";
			else cout<<r1/r2<<op<<i1/i2<<"i";
		}break;
		default:cout<<"error"<<endl;
	}
	return 0;
 } 
