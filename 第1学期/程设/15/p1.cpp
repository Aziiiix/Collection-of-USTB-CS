#include<iostream>
#include<string.h>
const  double  pi = 3.14;  //定义常量pi
using  namespace  std;
class  circle
{
public:
    circle(){}
    circle(double pr) :radius(pr) {};
    double radius;
    double getarea()
    {
        return pi*radius*radius;
    }
};
class  table
{
public:
    table(){}
    table(double pt) :height(pt) {};
    double height;
    double getheight()
    {
        return height;
    }
};
class  roundtable :public  circle, public  table
{
public:
    roundtable(double pr,double pt,char* pcolor):circle(pr),table(pt)
    {
        strcpy(color, pcolor);
    }
    void getcolor()
    {
        cout << color << endl;
    }
private:
    char color[50];
};
int  main()
{
    double a, b;
    char* pcolor = new char[50];
    cin >> a >> b >> pcolor;
    roundtable R(a, b, pcolor);
    cout << R.getarea() << endl;
    cout << R.getheight() << endl;
    R.getcolor();
    return  0;
}
