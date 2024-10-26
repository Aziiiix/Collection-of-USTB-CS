#include<iostream>
#include<cmath>
using  namespace  std;
int distance(int a,int b,int c,int d)
{ int x=(c-a)*(c-a)-(d-b)*(d-b);
  int y=sqrt(y);
  return y;
}
double distance(double a,double b,double c,double d)
{ double x=(c-a)*(c-a)-(d-b)*(d-b);
  double y=sqrt(y);
  return y;
}
int  main()
{
        int  a1,b1,a2,b2;
        cin  >>  a1  >>  b1  >>  a2  >>  b2;
        float  c1,d1,c2,d2;
        cin  >>  c1  >>  d1  >>  c2  >>  d2;
        cout  <<  distance(a1,b1,a2,b2)  <<  endl;
        cout  <<  distance(c1,d1,c2,d2)  <<  endl;
        return  0;
}
