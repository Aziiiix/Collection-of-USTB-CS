#include<iostream>
using namespace std;
int ans[10][7][8], block[10][6][7];
int record=1;
bool check(int num)
{
	for (int i = 2; i <= 6; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			ans[num][i][j] = block[num][i - 1][j] ^ ans[num][i - 1][j] ^ ans[num][i - 1][j - 1] ^
				ans[num][i - 1][j + 1] ^ ans[num][i - 2][j];
		}
	}
	for (int j = 1; j <= 6; j++)
		if (ans[num][6][j] == 1)
			return false;
	return true;
}

void solve(int num)
{
	for (int i = 0; i < 64; i++)  //枚举64次
	{
		int k = i;
		for (int j = 6; j >= 1; j--)
		{
			ans[num][1][j] = k % 2; //变为二进制
			k /= 2;
		}
		if (check(num))
			break;
	}
	cout<<"PUZZLE #"<<record<<endl;record++;
	for (int x = 1; x <= 5; x++)
	{
		for (int y = 1; y <= 6; y++)
		{
			cout << ans[num][x][y] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int allnum; cin >> allnum;
	for (int num = 0; num < allnum; num++)
	{
		for (int i = 0; i < 8; i++)
			ans[num][0][i] = ans[num][6][i] = 0; // 确定边界按钮状态
		for (int j = 1; j < 6; j++)
			ans[num][j][0] = ans[num][j][7] = 0; // 确定边界按钮状态
	}

	for (int num = 0; num < allnum; num++)
	{
		for (int x = 1; x <= 5; x++)
			for (int y = 1; y <= 6; y++)
				cin >> block[num][x][y];
	}
	
	for (int num = 0; num < allnum; num++)
	{
		solve(num);
	}
	return 0;
}
