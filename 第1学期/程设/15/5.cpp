#include<iostream> 
#include<cstring>
using namespace std;
class Account
{
public:
	Account(int accNumber, float balan)
	{
		acntNumber = accNumber; balance = balan; count++;
	};
	virtual void Withdrawal(float amount) = 0;// 取款
	void Deposit(float amount)// 存款
	{
		balance += amount;
	}
	int AccountNo(){return acntNumber;}// 账号
	void Display()// 显示信息
	{
		cout << acntNumber << " " << balance << endl;
	}
	static int NumOfAccount()
	{
		return count;
	}//账户总数
	virtual void SetRemit(int re) {} // 汇款
protected:
	static int count;// 用户数量
	int acntNumber;// 账号
	float balance;
};
int Account::count=0;
class Savings :public Account
{
public:
	Savings(int nr, float my):Account(nr, my) {};
	virtual void Withdrawal(float amount)
	{
		if (amount > balance) { cout <<acntNumber<< " Insufficient balance" << endl; }
		else { balance -= amount; }
	}
};
class Checking :public Account
{
public:
	Checking(int nr, float my) :Account(nr, my) {stat=1;};
	virtual void Withdrawal(float amount) {
		if(stat!=1){balance-=30;}
		if (amount > balance) { cout<<acntNumber << " Insufficient balance" << endl; }
		else { balance -= amount; }
	}
	virtual void SetRemit(int re) { stat=re; }
	private:
		int stat;
};
int main()
{
	Account *a1 = new Savings(1, 200);
	Account *a2 = new Checking(2, 500);
	a1->Display();
	a1->Withdrawal(100);
	a1->Deposit(50);
	a1->Display();
	a2->Deposit(200);
	a2->SetRemit(0);
	a2->Withdrawal(300);
	a2->Display();
	a2->Withdrawal(500);	
	cout << Account::NumOfAccount() << endl;
	a1->Withdrawal(50);
	a1->Display();
	return 0;
}
