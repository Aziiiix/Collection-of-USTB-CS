//code by Aziiii
#include<iostream>
using namespace std;

struct Student {
	char name[20];
	int score;
};
int main()
{
	Student groupA[6];
	for (int i = 0; i < 6; i++)
	{
		cin >> groupA[i].name;
		cin >> groupA[i].score;
	}//����ѧ����Ϣ���� 
	int groupAIndex[6];//������������ 
	for (int m = 0; m < 6; m++)
	{
		groupAIndex[m] = m;//���������±� 
	}
	for (int i = 1; i < 6; i++)
	{
		for (int j = 0; j < 6 - i; j++)
		{
			if (groupA[groupAIndex[j]].score> groupA[groupAIndex[j + 1]].score)
			{
				int temp = 0;
				temp = groupAIndex[j];
				groupAIndex[j] = groupAIndex[j + 1];
				groupAIndex[j + 1] = temp;
			}
		}
	}
	//�Ƚ�ԭ�������ʱ���ݴ�С�����������������ڵ��±�˳�� 

	for (int i = 0; i < 6; i++)
	{
		cout << groupA[groupAIndex[i]].name << " " << groupA[groupAIndex[i]].score << endl;
	}
	//�����±�˳�����ѧ����Ϣ 
	return 0;
}
