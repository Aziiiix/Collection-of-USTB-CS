#include<iostream>
#include<cstring>
using namespace std;
class Publication
{
public:
	Publication(){
	};
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

int main()
{
	Publication P;
	P.inputData("Publication", 120, "1999-2-1");
	P.display();
	cout << endl;
	return 0;
}
