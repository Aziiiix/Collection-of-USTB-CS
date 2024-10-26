#include<iostream>
using namespace std;
int f(int, int, int);
int main()
{
	int n,a[50],m;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	cin >> m;
	cout << f(n,a,m);
	return 0;
}
int f(int x,int a[],int y)
{
	int sum = 0;
	for (int i = 1;i <= x;i++)
	{
		sum *= y;
		sum += a[i];
	}
	return sum;
}
