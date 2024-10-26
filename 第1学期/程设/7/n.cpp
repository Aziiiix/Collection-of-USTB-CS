#include <iostream>
using namespace std;
int main()
{
 int m, a, i;
 for (m = 1; m <= 1000; m++)
 {
  a = 0;
  for (i = 1; i < m; i++)
  {
   if (m % i == 0)
   {
    a = a + i;
   }
  }
   if (a == m)cout << m << "  ";
 }
}
