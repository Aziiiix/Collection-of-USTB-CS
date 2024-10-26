#include"account.h"
#include<iostream>
#include<fstream>
#include<sstream>	
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

struct deleter
{
	template<class T>void operator()(T* p) { delete p; }
};
class Controller
{
private:
	Date date;
	vector<Account*>accounts;
	bool end;

public:
	Controller(const Date&date):date(date),end(false){}
	~Controller();
	const Date& getDate()const { return date; }
	bool isEnd()const { return end; }
	bool runCommand( const string & cmdLine,char cmd );
};

Controller::~Controller()
{
	for_each(accounts.begin(), accounts.end(), deleter());
}

bool Controller::runCommand(const string& cmdLine,char cmd)
{
	istringstream str(cmdLine);//逐行读入
	char type;
	int index, day;
	double amount, credit, rate, fee;
	string id, desc;
	Account* account;
	Date date1, date2;

	switch (cmd)
	{
	case 'a'://增加账户

		str >> type >> id;

		if (type == 's') {

			str >> rate;

			account = new SavingsAccount(date, id, rate);
		}

		else {

			str >> credit >> rate >> fee;

			account = new CreditAccount(date, id, credit, rate, fee);

		}

		accounts.push_back(account);

		return true;

	case 'd'://存入现金

		str >> index >> amount;

		getline(cin, desc);

		accounts[index]->deposit(date, amount, desc);

		return true;

	case 'w'://取出现金

		str >> index >> amount;

		getline(cin, desc);

		accounts[index]->withdraw(date, amount, desc);

		return true;

	case 's'://查询各账户信息

		for (size_t i = 0; i < accounts.size(); i++) {

			cout << "[" << i << "] ";

			accounts[i]->show();

			cout << endl;

		}

		return false;

	case 'c'://改变日期

		str >> day;

		if (day < date.getDay())

			cout << "You cannot specify a previous day";

		else if (day > date.getMaxDay())

			cout << "Invalid day";

		else

			date = Date(date.getYear(), date.getMonth(), day);

		return true;

	case 'n'://进入下个月

		if (date.getMonth() == 12)

			date = Date(date.getYear() + 1, 1, 1);

		else

			date = Date(date.getYear(), date.getMonth() + 1, 1);

		for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)

			(*iter)->settle(date);

		return true;

	case 'q'://查询一段时间内的账目

		str >> date1 >> date2;

		Account::query(date1, date2);

		return false;

	case 'e':
		end = true;
		return false;
	}

	cout << "Invalid command:" << cmdLine << endl;
	return false;
}

int main()
{
	Date date(2008, 11, 1);
	Controller controller(date);
	string cmdLine;
	const char* FILE_NAME = "conmmands.txt";
	ifstream fileIn(FILE_NAME);
	if (fileIn)
	{
		while (getline(fileIn, cmdLine))
			controller.runCommand(cmdLine,'0');
		fileIn.close();
	}
	ofstream fileOut(FILE_NAME, ios_base::app);
	cout << "(a)add account (d)deposit (w)withdraw (s)show (c)change day (n)next month (q)query (e)exit" << endl;

	while (!controller.isEnd())
	{
		cout << controller.getDate() << "       Total: " << Account::getTotal() << "        command>";
		string cmdLine;
		getline(cin, cmdLine);

		char cmd;

		if(cin>>cmd)
		{
			controller.runCommand(cmdLine, cmd);
			fileOut << cmdLine << endl;
		}
		else
		{
			break;
		}
	}
	return 0;
}