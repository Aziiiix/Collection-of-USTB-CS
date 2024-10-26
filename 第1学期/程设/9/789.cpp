#include <iostream>
using namespace std;
#include <cmath>
double f(int n)
{
 double aver = 0;
 double x = 0;
 for (int i = 0; i < n; i++)
 {
  cin >> x;
  aver += x;
 }
 aver = aver / n;
 return aver;
}

int main()
{   
 int n = 0;
 cin >> n;
 cout << f(n) << endl; 
 
 
 system("pause");
 return 0;
 } 
