#include<iostream>
#include<cmath>
using namespace std;
class MyRectangele
{
private:
	int xUp;
	int yUp;
	int xDown;
	int yDown;
public:
	MyRectangele()
	{
		xUp = 0; yUp = 0; xDown = 0; yDown = 0;
	}
	MyRectangele(int a = 0, int b = 0, int c = 0, int d = 0)
	{
		xUp = a; yUp = b; xDown = c; yDown = d;
	}
	int getW()
	{
		return fabs(xDown - xUp);
	}
	int getH()
	{
		return fabs(yUp - yDown);
	}
	int Area()
	{
		return (getW() * getH());
	}
};
int main()
{
	int a, b;
	cin >> a >> b;
	MyRectangele res(a, b, 0, 0);
	cout << "width=" << res.getW() << " " << "height=" << res.getH() << " " << "area=" << res.Area()<< endl;
	return 0;
}
