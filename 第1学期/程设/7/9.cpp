#include<iostream>

using namespace std;

bool Prime(int i) {//�ж��Ƿ�Ϊ�����ĺ���

    int j;

    if (i <= 1) return 0;//���С�ڵ���1����0

    if (i == 2) return 1;//�����2������1

    for (j = 2; j < i; j++) {//ѭ�������ж��Ƿ�Ϊ����

        if (i%j == 0)return 0;

        else if (i != j + 1) continue;

        else return 1;

    }

 

}

int main() {

    long i, j, k, flag1, flag2, n = 0;

    int a, b;
    cin >> a; 

    for (i = a; i>=1; i+=2) {//ż�����

        for (k = 2; k <= i / 2; k++) {//���ݸ���������ż����Ϊ������

            j = i - k;//��һ����

            flag1 = Prime(k);

            if (flag1) {//���kΪ����

                flag2 = Prime(j);

                if (flag2) {//jҲΪ����

                    cout << i << " = " << j << "+" << k<<"  ";

                    n++;

                    if (n % 5 == 0) cout << endl;//ÿ5������

                    break;

                }

            }

        }

    }
    system("pause");
    return 0;
}
