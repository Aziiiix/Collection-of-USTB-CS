#include<iostream>
using namespace std;
class Date
{
	public:
		Date(int Y,int M,int D);
		void disp_date();
	private:
		int year;
		int month;
		int day;
};
Date::Date(int Y,int M,int D)
{
	year=Y;
	month=M;
	day=D;
}
void Date::disp_date()
{
	cout<<year<<"."<<month<<"."<<day;
}
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	Date time(x,y,z);
	time.disp_date();
	return 0;
}
