#include<iostream>
using namespace std;
int main()
{
	int data[100], right[100];
	int sum;
	cin >> sum;
	for (int i = 0; i < sum; i++)
	{
		cin >> data[i];
	}//输入有序数字排序
	for (int i = 0; i < sum; i++)
	{
		if (i != sum - 1)
		{
			right[i] = i + 1;
		}
		else
		{
			right[i] = -1;//最后一位数字没有右侧元素
		}
	}//保存右侧元素的位置
	int insert;
	cin >> insert;//输入插入值
	int t=0;
	if(insert<data[0])
	{
		cout<<insert<<" ";
		while (t != -1)
	{
		cout << data[t] << " ";
		t = right[t];
	}
	return 0;
	}
	if(insert>data[sum-1])
	{
		while (t != -1)
	{
		cout << data[t] << " ";
		t = right[t];
	}
	cout<<insert<<" ";
	return 0;
	}
	sum++;
	data[sum - 1] = insert;//在数组末尾直接加上插入值
	t = 0;
	while (t >= 0)
	{
		if (data[right[t]] > insert)//如果下个值大于插入值
		{
			right[sum - 1] = right[t];//保存位置的数组末尾数指向本该指向的下个结点
			right[t] = sum - 1;//将下个结点指向数组末尾
			break;//插入完成跳出循环
		}
		t = right[t];
	}
	t=0;
	while (t != -1)
	{
		cout << data[t] << " ";
		t = right[t];
	}
	return 0;
}
