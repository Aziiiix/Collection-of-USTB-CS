#include<iostream>
using  namespace  std;
class  Shape                                                                      //基类Shape的定义
{
public:
	Shape() {}
	~Shape() {}
	double  getArea()const;
};
double Shape::getArea()  const
{
	return  0.0;
}

class Circle :public Shape
{
	public:
		Circle(double r = 0) { radius = r; }
		double getArea()const { return (3.14159) * radius * radius; }
	private:
		double radius;
};
class Rectangle :public Shape
{
	public:
		Rectangle(int aa = 0,int bb = 0) { a = aa; b = bb; }
		double getArea() { return a * b; }
	private:
		int a;
		int b;
};
class Square :public Rectangle
{
	public:
		Square(int bc) :Rectangle(bc,bc){};
};

int  main()
{
	Circle circle(3.5);
	Rectangle rectangle(5, 10);
	Square square(5);
	cout << "The  area  of  the  circle  is  " << circle.getArea() << endl;
	cout << "The  area  of  the  rectangle  is  " << rectangle.getArea() << endl;
	cout << "The  area  of  the  Square  is  " << square.getArea() << endl;
	return  0;
}
