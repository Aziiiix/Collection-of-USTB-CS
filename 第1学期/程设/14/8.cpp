#include<iostream>
using namespace std;
class Point
{
public:
	Point() {};
	void print()
	{
		cout << "This is Point" << endl;
	}
};
class Point3d :public Point
{
public:
	Point3d() {};
	void print()
	{
		cout << "This is 3D Point"<<endl;
	}
};
int main()
{
	Point3d test;
	test.Point::print();
	test.print();
	return 0;
}
