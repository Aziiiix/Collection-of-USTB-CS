#include<iostream>
#include<cstring>
using namespace std;
class Student
{
public:
	Student(char* pName, int Age, int Id);
	~Student();
	void getName(char* pName)
	{
		name = new char[strlen(pName) + 1];
		if (name != 0)strcpy(name, pName);
	}
	void getAge(int Age) { age = Age; }
	void getId(int Id) { id = Id; }
	void printf();
private:
	char* name;
	int age;
	int id;
};
Student::Student(char* pName, int Age, int Id)
{
	name = new char[strlen(pName) + 1];
	if (name != 0)strcpy(name, pName);
	age = Age;
	id = Id;
};
Student::~Student()
{
	delete[]name;
	name = 0;
}
void Student::printf()
{
	cout << "Name:" << name << " Age:" << age << " No:" << id;
}
int main()
{
	char* pName; int Age; int Id;
	pName = new char[100];
	cin >> pName >> Age >> Id;
	Student stu(pName, Age, Id);
	stu.printf();
	return 0;
}
