#include  <iostream>
#include  <cstring>
using  namespace  std;
//前向声明类Employee
class Employee;
class  Manager
{
public:
	Manager(int  pId, char* pN, int  pa);
	~Manager();
	friend void printManager(Manager& m);
	void printEmployee(Employee& e);
private:
	int id;
	char* name;
	int  age;
};
class Employee
{
	friend class Manager;
public:
	Employee(int  pId, char* pN, int  pa);
	~Employee();
private:
	int  id;
	char* name;
	int  age;
};
Manager::Manager(int  pId, char* pN, int  pa)
{
	id = pId;
	name = new char[strlen(pN) + 1];
	if (name != 0)strcpy(name, pN);
	age = pa;
}
Manager::~Manager()
{
	delete[]name;
	name = 0;
}
void  printManager(Manager& m)//  友元函数printManager的头部
{
	cout << "this  is  a  manager:  " << "id:  " << m.id << ",  " << "name:  " << m.name << ",  " << "age:  " << m.age << endl;
}
Employee::Employee(int  pId, char* pN, int  pa)
{
	id = pId;
	name = new char[strlen(pN) + 1];
	if (name != 0)strcpy(name, pN);
	age = pa;
}
Employee::~Employee()
{
	delete[]name;
	name = 0;
}
void  Manager::printEmployee(Employee& e)
{
	cout << "this  is  a  empylee:  " << "id:  " << e.id << ",  " << "name:  " << e.name << ",  " << "age:  " << e.age << endl;                  //实现打印某Employees信息
}
int  main()
{
	Manager  m1(1001, "zhangsan", 22);
	printManager(m1);                                              //调用友元函数输出Manager信息
	Employee  e1(2001, "lisi", 18);
	m1.printEmployee(e1);                                                  //通过友元类Manager输出Employee信息
	return  0;
}
