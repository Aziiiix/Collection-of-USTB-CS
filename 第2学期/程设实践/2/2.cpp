#include<iostream>
#include<cmath>
using namespace std;
class Position
{
public:
	int x, y, z;
};
int main()
{
	int All;
	cin >> All;
	Position* group = new Position[All];
	for (int i = 0; i < All; i++)
	{
		cin >> group[i].x >> group[i].y >> group[i].z;
	}
	int ans_time = 1000000;
	for (int i = 0; i < All; i++)
	{
		int sum=0;
		for (int j = 0; j < All; j++)
		{
			sum += (abs(group[i].x - group[j].x) + abs(group[i].y - group[j].y) + abs(group[i].z - group[j].z));
		}
		if (sum < ans_time)
			{
				ans_time = sum;
			}
	}

	cout << ans_time << endl;

	return 0;
}
