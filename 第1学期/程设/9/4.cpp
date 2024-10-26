#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f,g,h;
	cin>>a>>b>>c>>d>>e>>f>>g>>h;
	int num;
	cin>>num;
		if(num==a)cout<<1<<endl;
		if(num==b)cout<<2<<endl;
		if(num==c)cout<<3<<endl;
		if(num==d)cout<<4<<endl;
		if(num==e)cout<<5<<endl;
		if(num==f)cout<<6<<endl;
		if(num==g)cout<<7<<endl;
		if(num==h)cout<<8<<endl;
		if(num!=a&&num!=b&&num!=c&&num!=d&&num!=e&&num!=f&&num!=g&&num!=h)cout<<"cannot find"<<endl;
		return 0;
}
