#include  <iostream>      //  包含头文件iostream
#include  <cstring>
using  namespace  std;    //  使用命名空间std

//Engineer类的定义
class Engineer
{
public:
    void printEngineer();
    void setEngineer(int id, const char* name, const char* position);
    Engineer();
    Engineer(int id, const char* name, const char* position);
    ~Engineer();
private:
    int Id;
    char* Name;
    char* Position;
};
Engineer::Engineer()
{
}
Engineer::Engineer(int id, const char* name, const char* position)
{
    Id = id;
    Name = new char[strlen(name) + 1];
    if (Name != 0)strcpy(Name, name);
    Position = new char[strlen(position) + 1];
    if (Position != 0)strcpy(Position, position);
}
void Engineer::setEngineer(int id, const char* name, const char* position)
{
    Id = id;
    Name = new char[strlen(name) + 1];
    if (Name != 0)strcpy(Name, name);
    Position = new char[strlen(position) + 1];
    if (Position != 0)strcpy(Position, position);
}
Engineer::~Engineer()
{
	cout<<"destructing..."<<endl;
    Name[0] = '\0';
    delete[]Name;
    Name = NULL;
    Position[0] = '\0';
    delete[]Position;
    Position = NULL;
}
void  Engineer::printEngineer()
{
    cout << "id:  " << Id << ",  name:  " << Name << ",  position:  " << Position << endl;
}
int  main()
{
    Engineer  e[4];
    e[0].setEngineer(1001, "wanghan", "lecture");
    e[1].setEngineer(1002, "zhangqing", "lecture");
    e[2].setEngineer(1003, "zhaojing", "professor");
    e[3].setEngineer(1004, "yaolin", "professor");
    Engineer* pE1 = new  Engineer(1005, "fangwei", "professor");
    Engineer* pE2 = new  Engineer(1006, "huangling", "professor");
    e[0].printEngineer();
    e[1].printEngineer();
    e[2].printEngineer();
    e[3].printEngineer();
    pE1->printEngineer();
    pE2->printEngineer();
    delete  pE1, pE2;
    return  0;
}
