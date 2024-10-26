#include<iostream>
using namespace std;
int main()
{
	int year,month,days;
	cout<<"year:";
	cin>>year;
	cout<<"month:";
	cin>>month;
	switch(month)
	{
		case1:case3:case5:case7:case8:case10:case12:
			days=31;break;
			case4:case6:case9:case11:
				days=30;break;
				case2:if((year%4==0)&&(year%100!=0)||(year%400==0))
				days=29;
				else days=28;
	}
	cout<<"days:"<<days<<endl;
}
