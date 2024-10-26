#include<iostream>
#include<cstring>
using namespace std;
class Publication
{
public:
	Publication(){};
	~Publication()
	{
		delete[]name; name = 0;
		delete[]date; date = 0;
	}
	void inputData(const char* pName, int pPrice,const char* pDate)
	{
		strcpy(name, pName);
		price = pPrice;
		strcpy(date, pDate);
	}
	void display()
	{
		cout << name << " " << price << " " << date;
	}
private:
	char* name = new char[50];
	int price;
	char* date = new char[50];
};
class Book :public Publication
{
public:
	Book(){};
	~Book() {};
	void inputData(int pPage)
	{
		page = pPage;
	}
	void display()
	{
		cout <<" "<<page << endl;
	}
private:
	int page;
};
class Tape :public Publication
{
public:
	Tape() {};
	~Tape()
	{
		delete[]playtime; playtime = 0;
	}
	void inputData(const char* pPlaytime)
	{
		strcpy(playtime, pPlaytime);
	}
	void display()
	{
		cout <<" "<<playtime << endl;
	}
private:
	char* playtime = new char[50];
};
int main()
{
	Publication P;
	P.inputData("Publication", 120, "1999-2-1");
	P.display();
	cout << endl;
	Book B;
	B.Publication::inputData("Book", 30, "2009-1-1");
	B.inputData(300);
	B.Publication::display();
	B.display();
	Tape T;
	T.Publication::inputData("Tape", 15, "2003-5-1");
	T.inputData("00:48:10");
	T.Publication::display();
	T.display();
	return 0;
}
