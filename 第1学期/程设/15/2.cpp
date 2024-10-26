#include<iostream>
using namespace std;
#define Pi (3.141592)
class Shape
{
public:
	Shape(double lh, double wh = 0) :length(lh), width(wh) {};
	virtual void getArea() = 0;
	virtual void getGirth() = 0;
protected:
	double length;
	double width;
};
class Rectangle :public Shape
{
public:
	Rectangle(double lh, double wh) :Shape(lh, wh) {};
	void getArea()
	{
		cout << length * width << endl;
	}
	void getGirth()
	{
		cout << 2 * (length + width) << endl;
	}
};
class Circle :public Shape
{
public:
	Circle(double lh, double wh = 0) :Shape(lh, wh) {};
	void getArea()
	{
		cout << Pi * length * length << endl;
	}
	void getGirth()
	{
		cout << 2 * Pi * length << endl;
	}
};
int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	Rectangle R(a, b);
	R.getArea(); R.getGirth();
	Circle C(c);
	C.getArea(); C.getGirth();
	return 0;
}
