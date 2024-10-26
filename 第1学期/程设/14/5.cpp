#include<iostream>
#include<cstring>
using namespace std;
class Person
{
private:
	char* name = new char[20];
	int number;
public:
	Person() :number(0) {};
	Person(char* pName, int pNumber)
	{
		strcpy(name, pName);
		number = pNumber;
	}
	void getNameNumber()
	{
		cout << name << endl << number << endl;
	}
};
class Student
{
private:
	char* major = new char[20];
public:
	Student() {}
	Student(char* pMajor)
	{
		strcpy(major, pMajor);
	}
	void getMajor()
	{
		cout << major << endl;
	}
};
class Teacher
{
private:
	char* teach = new char[20];
public:
	Teacher() {}
	Teacher(char* pTeach)
	{
		strcpy(teach, pTeach);
	}
	void getTeach()
	{
		cout << teach << endl;
	}
};
class StudentTeacher :public Person, public Student, public Teacher
{
public:
	StudentTeacher() {}
	StudentTeacher(char* pName, int pNumber, char* pMajor, char* pTeach) :Person(pName, pNumber), Student(pMajor), Teacher(pTeach) {};
};
int main()
{
	char* pName = new char[20];
	char* pMajor = new char[20];
	char* pTeach = new char[20];
	int pNumber;
	cin >> pName >> pNumber >> pMajor >> pTeach;
	StudentTeacher f(pName, pNumber, pMajor, pTeach);
	f.getNameNumber(); f.getMajor(); f.getTeach();
	return 0;
}
