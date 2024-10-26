#include<iostream>
using namespace std;
struct Node
{
	int num;
	Node* next;
};
Node* head;Node* tail;

void creat(int m)
{
	Node *p,*q;
	p=new Node;
	p->num=1;p->next=NULL;
	head=p;
	q=p;
	for(int i=2;i<=m;i++)
	{
		p=new Node;
		p->num=i;
		q->next=p;
		q=p;
		p->next=NULL;
	}
	tail=q;
	tail->next=head;
}

void select(int n)
{
	int x=0;
	Node *p,*q;
	p=head;
	q=tail;
	do
	{
		x++;
		if(x%n==0)
		{
			
			q->next=p->next;
			delete p;p=NULL;
			p=q->next;
		}
		else
		{
			q=p;
			p=p->next;
		}
	}while(q!=q->next);
	head=q;
}

int main()
{
	int all,step;
	cin>>all>>step;
	creat(all);
	select(step);
	cout<<head->num<<endl;
	return 0;
}
