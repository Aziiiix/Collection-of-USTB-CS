#include  <iostream>      //  ����ͷ�ļ�iostream
#include  <cstring>
using  namespace  std;    //  ʹ�������ռ�std
class  Employee
{
public:
    Employee(int  pId, char* pName, char  pSex, char* pPosition);
    ~Employee();
    void  printEmployee();
    void  setSex(char  pSex);
private:
    int  id;                              //  ѧ��
    char* name;                    //  �����ַ�ָ�����
    char  sex;                          //  �Ա�
    char* position;          //  ְλ
};
//���캯������
Employee::Employee(int  pId, char* pName, char  pSex, char* pPosition)
{
    id = pId;
    name = new char[strlen(pName) + 1];
    if (name != 0)strcpy(name, pName);
    sex = pSex;
    position = new char[strlen(pPosition) + 1];
    if (position != 0)strcpy(position, pPosition);
}
Employee::~Employee() {
    delete[]  name;
    name = 0;
    delete[]  position;
    position = 0;
}
inline  void  Employee::printEmployee()
{
    cout << "id:  " << id << ",  " << "name:  " << name << ",  " << "sex:  " << sex << ",  " << "position:  " << position << endl;
}
//  �޸��Ա�ĺ���
void  Employee::setSex(char  pSex = 'M')
{
    if (pSex = 'F')
    {
        sex = 'M';
    }
}

int  main()
{
    Employee  emp(1001, "zhangxiao", 'F', "manager");
    emp.printEmployee();
    emp.setSex();
    emp.printEmployee();
    return  0;
}
