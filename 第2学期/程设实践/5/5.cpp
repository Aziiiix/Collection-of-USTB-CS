#include <iostream>
#include <cmath>
#define e 1e-6
using namespace std;
//��Ŀ�ǰ�4������������
//���ǰ������һ�� ��ɵ�һ�������� �ڶ���n-2������ ��n-2������ѡ������......
//ֱ���㵽ʣ��1������ʱ�� ��һ����Ҳ���Ǵ���
//�����⻯�ɶ��С���� ֱ�������ٻ�Ϊֹ
bool dfs(double a[], int n)
{
    if (n == 1)
    {
        if (fabs(a[0] - 24) <= e) //�������ĵȼ۱ȼ�
            return true;
        else
            return false;
    }
    double b[5];
    //�����û�������b������ (����������Ľ��Ҳ��b��) �൱��b�ĸ�����n-1
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            //����forѭ�� �ҳ����е������������
        {
            int m = 0; //��ʾb������ĸ���
            for (int k = 0; k < n; k++)
                //����a �ѵ�ǰ����Ϊ����������b��
            {
                if (k != i && k != j)
                    b[m++] = a[k];
            }
            //Ȼ��Ϳ�ʼ���������ʵ����
            b[m] = a[i] + a[j];
            if (dfs(b, m + 1))
                return true;
            b[m] = a[i] - a[j]; //��������
            if (dfs(b, m + 1))
                return true;
            b[m] = a[j] - a[i];
            if (dfs(b, m + 1))
                return true;
            b[m] = a[i] * a[j];
            if (dfs(b, m + 1))
                return true;
            if (a[j] != 0) //�ų���ĸΪ0�����
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
    return false;//����������˶������� �ǾͲ���
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

