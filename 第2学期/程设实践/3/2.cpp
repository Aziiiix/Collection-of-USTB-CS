#include<iostream>
using namespace std;

class Student
{
public:
	int s_id;
	char* s_name = new char[50];
};
class Major
{
public:
	int m_id;
	char* m_name = new char[50];
	int* stu = new int[50];
};

Student* G_S = new Student[50];
Major* G_M = new Major[50];

int main()
{
	
	int re1 = 0, re2 = 0;
	while(1)
	{
		char check; cin >> check;
		if(check=='e')
		{
			return 0;
		}
		if (check == 's')
		{
			G_S[re1].s_id = re1;
			cin >> G_S[re1].s_name;
			re1++;
		}
		if (check == 'n')
		{
			for (int a = 0; a < re1-1; a++)
			{
				cout<<G_S[a].s_id<<"-"<<G_S[a].s_name<<" ";
			}
			cout<<G_S[re1-1].s_id<<"-"<<G_S[re1-1].s_name<<endl;
		}
		if (check == 'm')
		{
			G_M[re2].m_id = re2;
			cin >> G_M[re2].m_name;
			for(int i=0;i<50;i++)
			{
				G_M[re2].stu[i]=(-1);
			}
			re2++;
		}
		if (check == 'l')
		{
			for (int b = 0; b < re2; b++)
			{
				cout << "Major " << G_M[b].m_id << "-" << G_M[b].m_name << ": ";
					for (int c = 0; c < 50; c++)
					{
						if(G_M[b].stu[c]==0)
						{
							cout<<G_S[c].s_id<<"-"<<G_S[c].s_name<<" ";
						}
						else continue;
					}
					cout<<endl;
			}
		}
		if(check=='a')
		{
			int x,y;cin>>x>>y;
			G_M[y].stu[x]=0; 
		}
		if(check=='d')
		{
			int x,y;cin>>x>>y;
			G_M[y].stu[x]=(-1);
		}
		if(check=='v')
		{
			int x,y,z;cin>>x>>y>>z;
			G_M[x].stu[y]=(-1);
			G_M[z].stu[y]=0;
		}
	}
	
	return 0;
}
