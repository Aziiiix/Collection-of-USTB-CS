#include<iostream>

using namespace std;

bool Prime(int i) {//判断是否为质数的函数

    int j;

    if (i <= 1) return 0;//如果小于等于1返回0

    if (i == 2) return 1;//如果是2，返回1

    for (j = 2; j < i; j++) {//循环遍历判断是否为质数

        if (i%j == 0)return 0;

        else if (i != j + 1) continue;

        else return 1;

    }

 

}

int main() {

    long i, j, k, flag1, flag2, n = 0;

    int a, b;
    cin >> a; 

    for (i = a; i>=1; i+=2) {//偶数相加

        for (k = 2; k <= i / 2; k++) {//根据鸽笼定理，将偶数分为两部分

            j = i - k;//另一部分

            flag1 = Prime(k);

            if (flag1) {//如果k为质数

                flag2 = Prime(j);

                if (flag2) {//j也为质数

                    cout << i << " = " << j << "+" << k<<"  ";

                    n++;

                    if (n % 5 == 0) cout << endl;//每5个换行

                    break;

                }

            }

        }

    }
    system("pause");
    return 0;
}
