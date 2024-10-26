/*
 * 冒泡排序
 */
#include <iostream>
#include <vector>

const int maxn = 5000;
int a[maxn];

// 交换函数，利用异或操作的可逆�?
void swap(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;
    if (n <= 0 || n > maxn)
    {
        std::cout << "Invalid input array length:\n"
            "   must be in the range of 1 to "
            << maxn << std::endl;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    // 冒泡排序
    for (bool flag = true; flag; )
    {
        flag = false;
        // 权值大的元素上�?
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                flag = true;
            }
        }
        // 权值小的元素下�?
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                flag = true;
            }
        }
        if(flag==false)break;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i] << (i < n - 1 ? ' ' : '\n');
    }
    return 0;
}
