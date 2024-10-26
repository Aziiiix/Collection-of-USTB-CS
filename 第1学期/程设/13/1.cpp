#include<iostream>
using namespace std;
class A
{
public: 
    static int count;//用来统计构造函数被调用的次数
    A(){count++;}
 int showcount(){return count;};
};
int A::count=0;
int main()
{
	A a;
	cout<<a.showcount()<<endl;
	A b;
	cout<<b.showcount()<<endl;
	return 0;
}
