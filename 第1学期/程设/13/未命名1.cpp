#include<iostream>
using namespace std;
int group[100], n;
void quicksort(int left, int right);
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> group[i];
	}
	quicksort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << group[i] << " ";
	}
	return 0;
}
void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left > right)exit(0);
	else
	{
		i = left;//����
		j = right;//����
		temp = group[left];//�洢��׼�����ұ��ֻ�׼�������
		while (i != j)
		{
			while (group[j] >= temp && i < j)
			{
				j--;
			}//��������Ѱ��
			while (group[i] <= temp && i < j)
			{
				i++;
			}//��������Ѱ��
			//Ѱ����ϣ���ʱ����бȻ�׼�����Ҳ��бȻ�׼��С
			if (i < j)
			{
				t = group[i];
				group[i] = group[j];
				group[j] = t;
				//��������λ��
			}
		}
		//��ʱ���ཻ����ϣ���׼��������࣬i��jͬʱָ�����м������
		group[left] = group[i];
		group[i] = temp;
		//��׼����λ
		//��ʱһ���������
		quicksort(left, i - 1);//�ݹ飬��߼�������
		quicksort(i + 1, right);//�ݹ飬�ұ߼�������
	}
}
