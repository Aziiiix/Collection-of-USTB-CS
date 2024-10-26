#include<iostream>
using namespace std;
class my_base {
	int a, b;
public:
	my_base(){}
	my_base(int x, int y)
	{
		a = x;
		b = y;
	}
	virtual void show()   //¶¨ÒåĞéº¯Êıshow()
	{
		cout << a << " " << b << endl;
	}
};
class my_class :public my_base
{
	int c;
public:
	my_class(int z) {
		c = z;
	}
	void show()
	{
		cout << c << endl;
	}
};
int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	my_base base(x, y);
	base.show();
	my_class mclass(z);
	mclass.show();
}
