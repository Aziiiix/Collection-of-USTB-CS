#include<iostream>
#include<cstring>
using namespace std;
#define Pi (3.14)
class Shape
{
public:
	Shape() :area(0) {};
	Shape(double parea) :area(parea) {};
	void print()
	{
		cout << area << endl;
	}
private:
	double area;
};
class Circle :public Shape
{
public:
	Circle(int pr) :r(pr), Shape(Pi * pr * pr) {};
	Circle() :r(0) {};
private:
	int r;
};
class Rectangle :public Shape 
{
public:
	Rectangle() :length(0), width(0) {};
	Rectangle(int pl, int pw) :length(pl), width(pw), Shape(pl* pw){};
private:
	int length; int width;
};
class Square :public Rectangle 
{
public:
	Square(int pb) :sin(pb),Rectangle(pb, pb) {};
private:
	int sin;
	
};
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	Circle C(a);
	Rectangle R(b, c);
	Square S(d);
	C.print(); R.print(); S.print();
}
