#include<iostream>
using  namespace  std;
const  int  MAXLENGTH = 10;  //�˴�����һ������MAXLENGTHΪ10
class CSet {
public:
	CSet(int a[], int psize);//������a��ǰsize��Ԫ�س�ʼ������
	bool AddElem(int e);//���Ԫ�أ��ɹ�����true�����򷵻�false
	void Print();
	CSet Intersection(CSet& set);
private:
	int data[MAXLENGTH];//���򱣴漯��Ԫ��
	int size;//���ϴ�С
};
CSet::CSet(int a[], int psize)
{
	for (int i = 0;i < psize; i++)
	{
		data[i] = a[i];
	}
	size = psize;
}
bool CSet::AddElem(int e)
{
	if(size<9)
	{
		data[size]=e;
		size+=1;
	}
}
CSet CSet::Intersection(CSet& set)
{
	int number=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<set.size;j++)
		{
			if(data[i]==set.data[j])
			{
				data[number]=data[i];
				number++;
				break;
			}
			if(data[i]!=set.data[j])
			{
				continue;
			}
		}
	}
}
void  CSet::Print()
{
	int  i;
	for (i = 0; i < size; i++)
		cout << data[i] << "  ";
	cout << endl;
}
int  main()
{
	int  a[8] = { 2,3,4,5,6,7,8,9 };
	int  b[10] = { 1,3,4,6,8,9,11,14,16,18 };
	int  x, y;
	cin >> x >> y;
	CSet  s1(a, x), s2(b, y);
	s1.Print();
	s2.Print();
	s1.AddElem(11);
	s1.Print();
	(s1.Intersection(s2)).Print();
	return  0;
}
