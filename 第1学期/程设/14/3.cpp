#include<iostream>
using namespace std;
class A
{
public: int n;
};
class B :public A {};
class C :public A {};
class D :public B, public C
{
	int getn() { return C::n; }
};
int main()
{
	D d;
	d.C::n = 10;
	cout << d.C::n << endl;
	return 0;
}
