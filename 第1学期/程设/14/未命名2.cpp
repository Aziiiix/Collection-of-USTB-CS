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
	}//����������������
	for (int i = 0; i < sum; i++)
	{
		if (i != sum - 1)
		{
			right[i] = i + 1;
		}
		else
		{
			right[i] = -1;//���һλ����û���Ҳ�Ԫ��
		}
	}//�����Ҳ�Ԫ�ص�λ��
	int insert;
	cin >> insert;//�������ֵ
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
	data[sum - 1] = insert;//������ĩβֱ�Ӽ��ϲ���ֵ
	t = 0;
	while (t >= 0)
	{
		if (data[right[t]] > insert)//����¸�ֵ���ڲ���ֵ
		{
			right[sum - 1] = right[t];//����λ�õ�����ĩβ��ָ�򱾸�ָ����¸����
			right[t] = sum - 1;//���¸����ָ������ĩβ
			break;//�����������ѭ��
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
