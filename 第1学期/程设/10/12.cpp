//code by Aziiii
#include<iostream>
#include<cstring> 
using namespace std;
int main()
{
	char** p;
	int number;
	cin >> number;
	p = new char* [number];
	for (int i = 0; i < number; i++)
	{
		cin >> p[i];
	}
	char* temp;//���ý���ֵtemp
	for (int i = 0; i < number-1; i++)
	{
		if (p[i][0] < p[i+1][0])
		{
			temp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = temp;
		}
	}//С������½������ߵ�ֵ
	for (int i = 0; i < number; i++)
	{
		cout << p[i] << endl;
	}
	return 0;
}
