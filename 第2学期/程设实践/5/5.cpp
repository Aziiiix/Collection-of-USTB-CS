#include <iostream>
#include <cmath>
#define e 1e-6
using namespace std;
//题目是把4个数进行运算
//我们把问题简化一下 变成第一次两个算 第二次n-2个数算 这n-2个数又选两个算......
//直到算到剩下1个数的时候 这一个数也就是答案了
//把问题化成多个小问题 直到不能再化为止
bool dfs(double a[], int n)
{
    if (n == 1)
    {
        if (fabs(a[0] - 24) <= e) //浮点数的等价比价
            return true;
        else
            return false;
    }
    double b[5];
    //把这个没算的数放b数组里 (这次两个数的结果也放b里) 相当于b的个数是n-1
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            //两成for循环 找出所有的两个数的组合
        {
            int m = 0; //表示b数组里的个数
            for (int k = 0; k < n; k++)
                //遍历a 把当前不作为算数的数放b里
            {
                if (k != i && k != j)
                    b[m++] = a[k];
            }
            //然后就开始四则运算的实验了
            b[m] = a[i] + a[j];
            if (dfs(b, m + 1))
                return true;
            b[m] = a[i] - a[j]; //减有两种
            if (dfs(b, m + 1))
                return true;
            b[m] = a[j] - a[i];
            if (dfs(b, m + 1))
                return true;
            b[m] = a[i] * a[j];
            if (dfs(b, m + 1))
                return true;
            if (a[j] != 0) //排除分母为0的情况
            {
                b[m] = a[i] / a[j];
                if (dfs(b, m + 1))
                    return true;
            }
            if (a[i] != 0)
            {
                b[m] = a[j] / a[i];
                if (dfs(b, m + 1))
                    return true;
            }
        }
    }
    return false;//如果上面试了都不能行 那就不行
}
int main()
{
    double group[10][4];
    int record=1;
    for (int num = 0; num < 10; num++)
    {
        int check; cin >> check;
        if (check != 0)
        {
            group[record][0] = check;
            cin >> group[record][1] >> group[record][2] >> group[record][3];
            record++;
        }
        if(check==0){break;}
    }

    for (int i = 1; i < record; i++)
    {
        double a[5];
        for (int j = 0; j < 4; j++)
        {
            a[j] = group[i][j];
        }
        if (dfs(a, 4))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

