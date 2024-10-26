#include<iostream>
#include<cstring>
using namespace std;
class Name
{
	public:
		Name(char*pn);
		~Name();
		void showName();
	protected:
	char *pName;
	int size; 
};
Name::Name(char*pn)
{
	cout<<"Constructing"<<pn<<endl;
	pName=new char[strlen(pn)+1];
	if(pName!=0)strcpy(pName,pn);
	size=strlen(pn);
}
Name::~Name()
{
	cout<<"Destructing"<<pName<<endl;
	pName[0]='\0';
	delete[]pName;
	pName=NULL;
	size=0;
}
void Name::showName()
{
	cout<<pName<<endl;
}
int main()
{
	Name Obj1("NoName");
	Obj1.showName();
}
