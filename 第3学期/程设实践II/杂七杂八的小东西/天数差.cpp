#include<iostream>
using namespace std;
int lapeyear(int year2)//�����жϺ���
{
	if ((year2 % 400 == 0) || (year2 % 4 == 0 && year2 % 100 != 0))
		return 1;
	else return 0;
}
int years1(int year1, int year2)//��������������
{
	int d = 0, i, r = 0, z = 0;
	if (year1 < year2)
	{
		for (i = year1 + 1; i < year2; i++)
		{
			if (lapeyear(i))r++;//����֮���ж��ٸ�����
		}
		d = (year2 - year1 - 1) * 365 + r;
	}
	else
	{
		for (i = year2 + 1; i < year1; i++)
		{
			if (lapeyear(i))r++;//����֮���ж��ٸ�����
		}
		d = (year1 - year2 - 1) * 365 + r;
	}
	return d;
}
int months2(int year, int month, int date)//���㵽����ղ�ĺ���
{
	int i, d = 0;
	int years[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (lapeyear(year))years[1] = 29;
	for (i = 0; i < month - 1; i++)
	{
		d += years[i];
	}
	d += date;
	return d;
}
int months1(int year, int month, int date)//���㵽����ղ�ĺ���
{
	int i, d = 0;
	int years[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (lapeyear(year))years[1] = 29;
	for (i = 11; i > month - 1; i--)
	{
		d += years[i];
	}
	d = d + years[month - 1] - date;
	return d;
}
int main()
{
	int year1, year2, month1, month2, date1, date2;
	int d = 0, i, m = 0;
	int x1, x2;//��¼�������ڷֱ��������׵�����
	int years[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	cout << "��������������" << endl;
	cin >> year1 >> month1 >> date1 >> year2 >> month2 >> date2;
	if (year1 == year2)//��ǰ�ᣬͬ��ʱ
	{
		if (lapeyear(year1))years[1] = 29;
		if (month1 == month2)d = date1 > date2 ? date1 - date2 : d = date2 - date1;//ͬ��ͬ��
		if (month1 != month2)//ͬ�겻ͬ��
		{
			//���㷽��Ϊ�������֮ǰ��������Ȼ����ǰһ����ʣ��������ͺ�һ�����Ѿ���ʼ������
			if (month1 < month2)
			{
				{
					for (i = month1; i < month2 - 1; i++)
					{
						m += years[i];
					}
				}
				d = years[month1 - 1] - date1;
				d += m + date2;
			}
			else
			{
					for (i = month2; i > month1 - 1; i++)
					{
						m += years[i];
		            }
				d = years[month2 - 1] - date2;
				d += m + date1;
			}
		}
	}
	else//��ͬ����������ڵ�������
	{
		if (year1 > year2)
		{
			x1 = months1(year2, month2, date2);//x1Ϊ����׵��ղx2Ϊ��������ղ�
			x2 = months2(year1, month1, date1);
			d = years1(year2, year1);
			d += x1 + x2;
		}
		else
		{
			x2 = months2(year2, month2, date2);
			x1 = months1(year1, month1, date1);
			d = years1(year1, year2);
			d += x1 + x2;
		}

	}
	cout << "����֮���������Ϊ" << " " << d;
	return 0;
}

