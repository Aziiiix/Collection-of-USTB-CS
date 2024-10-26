#include<iostream>
using namespace std;
class Course
{
	public:
		int number;
		char* name=new char[100];
		int first;
	};
int main()
{
	int record=0;
	Course* Co=new Course[101];
	
	for(int i=0;i<100;i++)
	{
		char check;
		cin>>check;
		if(check=='e'){exit(0);}
		if(check=='c')
		{
			Co[record].number=record;
			cin>>Co[record].name>>Co[record].first;
			record++;
		}
		if(check=='s')
		{
			for(int i=0;i<record;i++)
			{
				cout<<"Course "<<i<<"-"<<Co[i].name<<" has prerequisites: ";
				if(Co[i].first==(-1)){cout<<"none"<<endl;}
				else
				{for(int j=Co[i].first;j>=0;j--){
					if(j==0){cout<<Co[j].name<<endl;}
					else{cout<<Co[j].name<<" ";}}}
			}
		}
	}
	
	return 0;
}
