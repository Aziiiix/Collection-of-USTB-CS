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
	head = NULL;//头指针初始为空
	int sum;
	cin >> sum;
	for (int i = 0; i < sum; i++)
	{
		int a; 
		cin >> a;//读入所存放的数
		p = new node[sizeof(struct node)];//动态创建一个结构体大小的空间并指向这个空间
		p->data = a;
		p->next = NULL;//初始指针为空
		if (head == NULL)//如果头指针为空
		{
			head = p;//则头指针指向这个结点
		}
		else
		{
			q->next = p;//上一个结点指针指向这个结点
			q = p;//指针q指向当前结点
		}
	}
	node* t=head;//创立新的指针指向头指针
	int insert;
	cin >> insert;//输入将要插入的值
	while (t!=NULL)
	{
		if (t->next->data > insert)//如果下一个结点的值大于插入值
		{
			p = new node[sizeof(struct node)];//新建一个结点
			p->data = insert;//存放插入值
			p->next = t->next;//指向下一个结点
			t->next = p;//指针指向当前位置
			break;//插入完毕结束循环
		}
		t = t->next;//继续指向下一个位置
	}
	t = head;
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}
	return 0;
}
