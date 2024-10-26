#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	float a,b,c,d,jp,ip;
	cin>>a>>b>>c;
	d=b*b-4*a*c;
	jp=(-b)/(2*a);
	ip=sqrt(-d)/(2*a);
	if (d==0){cout<<"has two equal roots:\n";
		cout<<"x1=x2="<<-b/(2*a)<<endl;
	}
	else if(d>0){
		cout<<"has two real roots:\n";
		cout<<"x1="<< (-b+sqrt(d))/(2*a)<<",x2="<< (-b-sqrt(d))/(2*a)<<endl;
	}
	else if(d<0){
		cout<<"has two complex roots:\n";
		cout<<"x1="<<jp<<"+"<<ip<<"i\n"<<"x2="<<jp<<"-"<<ip<<"i"<<endl;
	}
	return 0;
}
