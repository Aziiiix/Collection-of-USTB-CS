#include<iostream>
#include<cstring> 
using namespace std;
#define Pi (3.1415926)
class Circle
{
public:
	Circle() :radius(0) {};
	Circle(double r) :radius(r) {};
	double getarea()
	{
		return Pi * radius * radius;
	}
private:
	double radius;
};
class Table
{
public:
	Table() :height(0) {};
	Table(double h) :height(h) {};
	double getheight()
	{
		return height;
	}
private:
	double height;
};
class Roundtable:public Circle,public Table
{
public:
	Roundtable() :color(0) {};
	Roundtable(double r, double h, char* pColor) :Circle(r), Table(h)
	{
		strcpy(color, pColor);
	}
	~Roundtable()
	{
		delete[]color;
		color=0;
	}
	void print()
	{
		cout<<color<<endl;
	}
private:
	char* color=new char [20];
};
int main()
{
	double r, h;
	cin >> r >> h;
	char* pColor=new char [20];
	cin >> pColor;
	Roundtable Nice(r, h, pColor);
	cout << Nice.getarea() << endl << Nice.getheight() << endl;
	Nice.print();
	return 0;
}
