#include<iostream>
using namespace std;
int group[100], n;
void quicksort(int left, int right);
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> group[i];
	}
	quicksort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << group[i] << " ";
	}
	return 0;
}
void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left > right)exit(0);
	else
	{
		i = left;//左起；
		j = right;//右起；
		temp = group[left];//存储基准数，且保持基准数在左侧
		while (i != j)
		{
			while (group[j] >= temp && i < j)
			{
				j--;
			}//从右向左寻找
			while (group[i] <= temp && i < j)
			{
				i++;
			}//从左向右寻找
			//寻找完毕，此时左侧有比基准数大，右侧有比基准数小
			if (i < j)
			{
				t = group[i];
				group[i] = group[j];
				group[j] = t;
				//交换两者位置
			}
		}
		//此时两侧交换完毕，基准数在最左侧，i和j同时指向最中间的数字
		group[left] = group[i];
		group[i] = temp;
		//基准数归位
		//此时一次排序完成
		quicksort(left, i - 1);//递归，左边继续排序
		quicksort(i + 1, right);//递归，右边继续排序
	}
}
