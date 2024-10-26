#include<iostream>
using namespace std;
int lapeyear(int year2)//闰年判断函数
{
	if ((year2 % 400 == 0) || (year2 % 4 == 0 && year2 % 100 != 0))
		return 1;
	else return 0;
}
int years1(int year1, int year2)//计算两年间的天数
{
	int d = 0, i, r = 0, z = 0;
	if (year1 < year2)
	{
		for (i = year1 + 1; i < year2; i++)
		{
			if (lapeyear(i))r++;//两年之间有多少个闰月
		}
		d = (year2 - year1 - 1) * 365 + r;
	}
	else
	{
		for (i = year2 + 1; i < year1; i++)
		{
			if (lapeyear(i))r++;//两年之间有多少个闰月
		}
		d = (year1 - year2 - 1) * 365 + r;
	}
	return d;
}
int months2(int year, int month, int date)//计算到年初日差的函数
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
int months1(int year, int month, int date)//计算到年底日差的函数
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
	int x1, x2;//记录两个日期分别到年初和年底的天数
	int years[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	cout << "请输入两个日期" << endl;
	cin >> year1 >> month1 >> date1 >> year2 >> month2 >> date2;
	if (year1 == year2)//大前提，同年时
	{
		if (lapeyear(year1))years[1] = 29;
		if (month1 == month2)d = date1 > date2 ? date1 - date2 : d = date2 - date1;//同年同月
		if (month1 != month2)//同年不同月
		{
			//计算方法为求出两月之前的天数，然后求前一个月剩余的天数和后一个月已经开始的天数
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
	else//求不同年的任意日期的天数差
	{
		if (year1 > year2)
		{
			x1 = months1(year2, month2, date2);//x1为到年底的日差，x2为到年初的日差
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
	cout << "两年之间的天数差为" << " " << d;
	return 0;
}

