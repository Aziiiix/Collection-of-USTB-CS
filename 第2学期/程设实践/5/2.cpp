#include<iostream>
using namespace std;

int length, width;
char map[20][20];
int sum = 0;

void judge(int x, int y)
{
	if (x < 0 || y < 0 || x == width || y == length || map[x][y] == '#') { return; }
	map[x][y] = '#';
	sum++;
	judge(x - 1, y); judge(x + 1, y); judge(x, y + 1); judge(x, y - 1);
}

int main()
{
	cin >> length >> width;
	int startx, starty;
	for (int i = 0; i < width; i++)
	{
		cin >> map[i];
	}//ÊäÈëµØÍ¼
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (map[i][j] == '@')
			{
				startx = i; starty = j;
			}
		}
	}
	judge(startx, starty);
	cout << sum << endl;
	return 0;
}
