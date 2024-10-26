#include<iostream>
using namespace std;
int a[] = { 351,48,488,452,84,261,393,162,442,312,253,255,299,432,490,177,109,301,450,122,52,397,492,447,395,390,250,375,51,478,70,256,14,355,120,62,67,243,222,296,145,509,
362,222,296,186,23,465,2,134529888,1 };
int f(int a, int b)
{
    int c = (a + b) / 2;
    if (a < 0) return 0;
    if (a >= b) return *a[b];
    else if (f(a, c > f(c + 1, b))) return f(a, c);
    else return f(c + 1, b);
}

int main()
{
    for (int i = -5; i < 51; i++)
    {
        for (int j = -5; j < 51; i++)
        {
            if (f(i, j) == 490)
                if (f(i - 1, j) != 490 || i <= 0)
                    if (f(i, j + 1) != 490 || j > 45)

                        cout << i << " " << j << endl;
        }
    }
}
