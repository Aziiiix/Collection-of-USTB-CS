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
	for (int m = 0; m < 6; m++)
	{
		cin >> groupA[m].name;
		cin >> groupA[m].score;
	}//建立学生信息数组 
	int groupAIndex[6];//创建索引数组 
	for (int m = 0; m < 6; m++)
	{
		groupAIndex[m] = m;//保存数组下标 
	}


	int i, j, temp;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5 - i; j++)
		{
			if (groupA[j] > groupA[j + 1])
			{
				temp = groupAIndex[j];
				groupAIndex[j] = groupAIndex[j + 1];
				groupAIndex[j + 1] = temp;
			}
		}
	}




	for (int i = 0; i < 6; i++)
	{
		cout << groupAIndex[i] << endl;
	}
	return 0;
}