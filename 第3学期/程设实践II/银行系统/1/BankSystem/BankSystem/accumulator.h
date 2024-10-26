//accmulator.h

#ifndef _ACCUMULATOR_H_
#define _ACCUMULATOR_H_

#include"date.h"

class Accumulator
{
private:
	Date lastDate;
	double value;
	double sum;

public:
	Accumulator(const Date&date,double value)
		:lastDate(date),value(value),sum(0){}
	double getSum(const Date& date)const//计算累计值
	{
		return sum + value * (date-lastDate);
	}
	void change(const Date& date, double value)//修改累计值 上次更改日期
	{
		sum = getSum(date);
		lastDate = date; this->value = value; 
	}
	void reset(const Date& date, double value)//结息重置累计值 修改更改日期
	{
		lastDate = date;
		this->value = value;
		sum = 0;
	}
};

#endif // !_ACCUMULATOR_H_
