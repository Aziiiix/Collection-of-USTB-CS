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
		for(int j=0;j<=5-i;j++)
		{
		if (groupA[j].score > groupA[j + 1].score)
		{
			int temp = 0;
			temp = groupAIndex[j];
			groupAIndex[j] = groupAIndex[j + 1];
			groupAIndex[j + 1] = temp;//��������������������±���������
		}
	}
	}
	for (int i = 0; i < 6; i++)
	{
		cout << groupA[groupAIndex[i]].name << " " << groupA[groupAIndex[i]].score << endl;
	}
	return 0;
}
