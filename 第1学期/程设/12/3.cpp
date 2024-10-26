#include<iostream>
using namespace std;
class Rectangle
{
	public:
		Rectangle(int x,int y)
		{
			length=x;
			width=y;
		}
		void getArea()
		{
			cout<<length*width<<endl;
		}
	private:
		int length;
		int width;
};
int main()
{
	int x,y;
	cin>>x>>y;
	Rectangle grow(x,y);
	grow.getArea();
	return 0;
}
