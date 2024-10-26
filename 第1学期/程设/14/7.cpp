#include<iostream>
#include<cstring>
using namespace std;
class Document
{
public:
	Document() {};
	Document(char* pName)
	{
		strcpy(name, pName);
	}
	~Document()
	{
		delete[]name; name = 0;
	}
	void PrintNameOf()
	{
		cout << name;
	}
private:
	char* name = new char[50];
};
class Book :public Document
{
public:
	Book(char* pName, long pagecount) :Document(pName), PageCount(pagecount) {};
	void PrintNameOf()
	{
		cout << PageCount;
	}
private:
	long PageCount;
};
int main()
{
	string d;
	cin >> d;
	char* pName = new char[50];
	long number;
	cin >> pName >> number;
	Book Time(pName, number);
	cout << "Name of book: "; Time.Document::PrintNameOf();
}

