//date.h

#ifndef _DATE_H_
#define _DATE_H_

#include<iostream>

class Date
{
private:
	int year;
	int month;
	int day;
	int totalDays;

public:
	Date()
		:year(0),month(0),day(0),totalDays(0){}
	Date(int year, int month, int day);
	//static Date read();
	int getYear()const { return year; }
	int getMonth()const { return month; }
	int getDay()const { return day; }
	int getMaxDay()const;
	bool isLeapYear()const
	{
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	void show()const;

	int operator-(const Date& date)const//����������
	{
		return totalDays - date.totalDays;
	}
	bool operator<(const Date& date)const//�����ж�����
	{
		return totalDays < date.totalDays;
	}
};

std::istream& operator>>(std::istream& in, Date& date);
std::ostream& operator<<(std::ostream& out, const Date& date);//��������������

#endif // !_DATE_H_
