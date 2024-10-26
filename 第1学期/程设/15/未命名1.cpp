#include<iostream>
using namespace std;
class Shape
{
public:
	float GetArea(float x, float y)
	{
		return x * y;
	}
protected:
	float x;
	float y;
};
class Rectangle : public Shape {
};
class Circle : public Shape
{
public:
	float cm(float x, float y) {
		float sm=3.14 * GetArea(float x, float y);
		cout<<sm;
	}
};
class Square : public Rectangle
{
};
int main()
{
	float x, y, z, w;
	cin >> x >> y >> z >> w;
	Circle c;
	c.cm(x, x);
	Rectangle r;
	cout << r.GetArea(y, z);
	Square s;
	cout << s.GetArea(w, w);

}
