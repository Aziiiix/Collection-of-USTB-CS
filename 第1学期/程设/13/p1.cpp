#include  <iostream>      
#include  <cstring>
using  namespace  std;    
class  Manager
{
	public:
		Manager(int  pId,char*  pName,int  pAge);
		~Manager();
		friend void printManager(Manager& manager);
	private:
	int id;
	char* name;
	int age;
};
Manager::Manager(int  pId,char*  pName,int  pAge)
{
	id=pId;
	name=new char[strlen(pName)+1];
	strcpy(name,pName);
	age=pAge; 
    cout<<"Constructed  with  all  parameters."<<endl;
}
Manager::~Manager()
{
	delete[]name;
	name=0;
    cout<<"Deconstructed."<<endl;
}
void  printManager(Manager&  manager)
{
    cout<<"id:  "<<manager.id<<",  "<<"name:  "<<manager.name<<",  "<<"age:  "<<manager.age<<endl;
}
int  main()
{
    Manager  m1(1001,"zhangsan",22);
    printManager(m1);
    return  0;
}
