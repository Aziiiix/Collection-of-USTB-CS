#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
int main()
{
	node* head, * p, * q=NULL;
	head = NULL;//ͷָ���ʼΪ��
	int sum;
	cin >> sum;
	for (int i = 0; i < sum; i++)
	{
		int a; 
		cin >> a;//��������ŵ���
		p = new node[sizeof(struct node)];//��̬����һ���ṹ���С�Ŀռ䲢ָ������ռ�
		p->data = a;
		p->next = NULL;//��ʼָ��Ϊ��
		if (head == NULL)//���ͷָ��Ϊ��
		{
			head = p;//��ͷָ��ָ��������
		}
		else
		{
			q->next = p;//��һ�����ָ��ָ��������
			q = p;//ָ��qָ��ǰ���
		}
	}
	node* t=head;//�����µ�ָ��ָ��ͷָ��
	int insert;
	cin >> insert;//���뽫Ҫ�����ֵ
	while (t!=NULL)
	{
		if (t->next->data > insert)//�����һ������ֵ���ڲ���ֵ
		{
			p = new node[sizeof(struct node)];//�½�һ�����
			p->data = insert;//��Ų���ֵ
			p->next = t->next;//ָ����һ�����
			t->next = p;//ָ��ָ��ǰλ��
			break;//������Ͻ���ѭ��
		}
		t = t->next;//����ָ����һ��λ��
	}
	t = head;
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}
	return 0;
}
