//account.cpp

#include"account.h"
#include<string>
#include<cmath>
#include<iostream>
#include<utility>

using namespace std;
using namespace std::rel_ops;

AccountRecord::AccountRecord(const Date &date, const Account* account, double amount, double balance,const string& desc)
	:date(date),account(account),amount(amount),balance(balance),desc(desc){}

void AccountRecord::show()const
{
	cout << date << "\t#" << account->getId() << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

double Account::total = 0;
RecordMap Account::recordMap;

void Account::query(const Date& begin, const Date& end)
{
	if (begin <= end)//迭代器
	{
		RecordMap::iterator iter1 = recordMap.lower_bound(begin);//lower_bound取<begin最小
		RecordMap::iterator iter2 = recordMap.upper_bound(end);//lower_bound取>end最大
		for (RecordMap::iterator iter = iter1; iter!=iter2; ++iter)
		{
			iter->second.show();
		}
	}
}

Account::Account(const Date& date, const string& id)
	:id(id), balance(0)
{
	cout << date << "\t#" << id << " created" << endl;
}

void Account::record(const Date& date, double amount, const string& desc)
{
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;

	AccountRecord record(date, this, amount, balance, desc);
	recordMap.insert(make_pair(date, record));//map记录账目
}

void Account::show()
{
	cout << id << "\tBalance:" << balance;
}

void Account::show(ostream &out)const
{
	out << id << "\tBalance:" << balance;
}

void Account::error(const string& msg)const
{
	cout << "Error(#" << id << "):" << msg << endl;
}

SavingsAccount::SavingsAccount(const Date& date, const string& id, double rate)
	:Account(date, id), rate(rate), acc(date, 0) {}

void SavingsAccount::deposit(const Date& date, double amount, const string& desc)
{
	record(date, amount, desc);
	acc.change(date, getBalance());
}

void SavingsAccount::withdraw(const Date &date,double amount,const string&desc)
{
	if (amount > getBalance())
		error("not enough money");
	else
		record(date, -amount, desc); acc.change(date, getBalance());
}

void SavingsAccount::settle(const Date& date)
{
	if (date.getMonth() == 1)
	{
		double interest = acc.getSum(date) * rate / (date - Date(date.getYear() - 1, 1, 1));
		if (interest != 0)
			record(date, interest, "interest");
		acc.reset(date, getBalance());
	}
}

CreditAccount::CreditAccount(const Date&date,const string&id,double credit,double rate,double fee)
	:Account(date,id),credit(credit),rate(rate),fee(fee),acc(date,0){}

void CreditAccount::deposit(const Date& date, double amount, const string &desc)
{
	record(date, amount, desc);
	acc.change(date, getDebt());
}

void CreditAccount::withdraw(const Date& date, double amount, const string &desc)
{
	if (amount - getBalance() > credit)
	{
		error("not enough credit");
	}
	else
	{
		record(date, -amount, desc);
		acc.change(date, getDebt());
	}
}

void CreditAccount::settle(const Date& date)
{
	double interest = acc.getSum(date) * rate;
	if (interest != 0)
		record(date, interest, "interest");
	if (date.getMonth() == 1)
		record(date, -fee, "annual fee");
	acc.reset(date, getDebt());
}

void CreditAccount::show()
{
	Account::show();
	cout << "\tAvailable credit:" << getAvailableCredit();
}

void CreditAccount::show(ostream& out)const
{
	Account::show(out);
	out << "\tAvailable credit:" << getAvailableCredit();
}