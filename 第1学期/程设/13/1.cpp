#include<iostream>
using namespace std;
class A
{
public: 
    static int count;//����ͳ�ƹ��캯�������õĴ���
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
