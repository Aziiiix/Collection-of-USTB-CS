#include<iostream>
using namespace std;

class MyStack
{
	private:
	int *m_array=new int [10];
	int m_size=0;
	public:
		MyStack(){}
	void push(int x)
	{
		if(m_size==10)cout<<"false"<<endl;
		else{m_array[m_size]=x; m_size++;}
	}
	void pop()
	{
		if(m_size==0){cout<<"Can not pop empty stack"<<endl;exit(0);}
		else{m_size--;}
	}
	void print()
	{
		cout<<"( ";
		for(int i=0;i<m_size;i++)
		{
			cout<<m_array[i]<<" ";
		}
		cout<<")"<<endl;
		exit(0); 
	}
};

int main()
{
	MyStack Stack;
	for(int i=0;i<100;i++)
	{
		char check;cin>>check;
		if(check=='i')
		{
			int num;cin>>num;
			Stack.push(num);
		}
		if(check=='o'){Stack.pop();}
		if(check=='s'){Stack.print();}
	}
}
