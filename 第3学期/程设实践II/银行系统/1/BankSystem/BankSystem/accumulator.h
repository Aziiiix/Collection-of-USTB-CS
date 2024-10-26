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
	double getSum(const Date& date)const//�����ۼ�ֵ
	{
		return sum + value * (date-lastDate);
	}
	void change(const Date& date, double value)//�޸��ۼ�ֵ �ϴθ�������
	{
		sum = getSum(date);
		lastDate = date; this->value = value; 
	}
	void reset(const Date& date, double value)//��Ϣ�����ۼ�ֵ �޸ĸ�������
	{
		lastDate = date;
		this->value = value;
		sum = 0;
	}
};

#endif // !_ACCUMULATOR_H_
