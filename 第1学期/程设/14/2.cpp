#include<iostream>
using namespace std;
class Point
{
public:    //公有函数成员
    void InitP(float xx = 0, float yy = 0) { X = xx; Y = yy; }
    void Move(float xOff, float yOff) { X += xOff; Y += yOff; }
    float GetX() { return X; }
    float GetY() { return Y; }
private:    //私有数据成员
    float X, Y;
};
class Rectangle :public Point
{
private:
    int length;
    int width;
public:
    Rectangle(int a, int b)
    {
        length = a;
        width = b;
    }
    int GetLength()
    {
        return length;
    }
    int GetWidth()
    {
        return width;
    }
};
int main()
{
    int a, b, c, d, e, f;
    cin>>a>>b>>c>>d;
    cin>>e>>f;
    Rectangle Start(c, d);
    Start.InitP(a, b);
    Start.Move(e, f);
    cout << Start.GetX() << " " << Start.GetY() << " " << Start.GetLength() << " " << Start.GetWidth();
}
