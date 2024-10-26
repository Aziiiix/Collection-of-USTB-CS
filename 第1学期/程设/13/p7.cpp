#include  <iostream>      //  ����ͷ�ļ�iostream
#include  <cstring>
using  namespace  std;    //  ʹ�������ռ�std

//Employee�Ķ���
class Employee
{
	static int count;
	static int allAges;
	private:
		int id;
		char* name;
		int age;
	public:
		Employee(int  pId,char*  pName,int  pAge);
		~Employee();
		void printEmployee();
		void printStat();
};

Employee::Employee(int  pId,char*  pName,int  pAge)
{
	id=pId;
	name=new char[strlen(pName)+1];
	strcpy(name,pName);
	age=pAge;
	count++;
	allAges+=age;
//�Գ�Ա���ݸ�ֵ

  cout<<"Constructed  with  all  parameters."<<endl;
}
//��̬��Ա��ʼ��
int Employee::count=0;
int Employee::allAges=0;

Employee::~Employee()
{
delete[]name;
name=0;
            cout<<"Deconstructed."<<endl;
}
void  Employee::printEmployee()
{
            cout<<"id:  "<<id<<",  "
            <<"name:  "<<name<<",  "
            <<"age:  "<<age<<endl;
}
void  Employee::printStat()
{
        cout<<"The  number  of  employees  is:  "<<count<<endl;
        cout<<"The  average  age  is:  "<<(float)(allAges)/count<<endl;
}
int  main()
{
          Employee  e1(1001,"zhangsan",22);
          Employee  e2(1002,"lisi",23);
          Employee  e3(1003,"wangwu",25);
          Employee  e4(1004,"zhouliu",20);
          e1.printStat();
          return  0;
}
