#include<iostream>
#include<algorithm>
using  namespace  std;
void mySort(int*& a, int n)
{
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int  main()
{
	int  i, n;
	int* a = 0;
	cin >> n;
	mySort(a, n);
	for (i = 0; i < n; i++)
	cout << a[i] << "  ";
	cout << endl;
	delete[]  a;
	return  0;
}
