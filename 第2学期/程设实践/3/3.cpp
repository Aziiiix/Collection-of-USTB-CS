#include<iostream>
using namespace std;

class Point2D
{
public:
	int x, y;
	Point2D(){}
};

class Creature
{
public:
	char* Name = new char[50];
	int id;
	Point2D Location;
	Creature(){}
};

Creature* Group = new Creature[50];

int main()
{
	int record = 0;
	for (int i = 0; i < 100; i++)
	{
		char check; cin >> check;
		if (check == 'n')
		{
			char* name = new char[50]; int px, py; cin >> name >> px >> py;
			Group[record].Name = name; Group[record].Location.x = px; Group[record].Location.y = py; Group[record].id = record;
			record++;
			continue;
		}
		if (check == 's')
		{
			int num; cin >> num;
			cout << "No. " << num << " creature " << Group[num].Name << " is at (" << Group[num].Location.x << ", " << Group[num].Location.y << ")" << endl;
			continue;
		}
		if (check == 'a')
		{
			for(int a=0;a<record;a++)
			{
				cout << "No. " << a << " creature " << Group[a].Name << " is at (" << Group[a].Location.x << ", " << Group[a].Location.y << ")" << endl;
			}
			continue;
		}
		if (check == 'm')
		{
			int pid, px, py; cin >> pid >> px >> py;
			Group[pid].Location.x = px;
			Group[pid].Location.y = py;
			continue;
		}
		if(check=='e')
		{
			return 0;
		}
	}
}
