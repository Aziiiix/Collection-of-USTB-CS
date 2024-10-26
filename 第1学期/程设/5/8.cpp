#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c;
	d=b*b-4*a*c;
	if (d==0){cout<<"has two equal roots:\n";
		cout<<"x1=x2="<<-b/(2*a)<<endl;
	}
	else if(d>0){
		cout<<"has two real roots:\n";
		cout<<"x1="<<(-b-sqrt(d))/(2*a)<<endl;
		cout<<"x2="<<(-b-sqrt(d))/(2*a)<<endl;
	}
	else if(d<0){
		cout<<"has two complex roots:\n";
		cout<<"x1="<<(-b/(2*a))+(sqrt(-d)/(2*a))<<"i"<<endl;
		cout<<"x2="<<(-b/(2*a))-(sqrt(-d)/(2*a))<<"i"<<endl;
	}
	return 0;
}
