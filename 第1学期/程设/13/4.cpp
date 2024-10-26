#include<iostream>
using namespace std;
class A
{
	static int count;
	public:
		A();
		~A();
 } ;
 int A::count=0;
 A::A()
 {
 	count++;
 	cout<<count<<endl;
 }
 A::~A()
 {
 	count--;
 	cout<<count<<endl;
 }
 int main()
 {
 	A Love;
 	return 0;
 }
