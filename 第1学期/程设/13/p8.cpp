#include  <iostream>
using  namespace  std;
class  Student{
        private  :
                char  *name;
                int  age;
                char  *no;
        public  :
                Student(char*  name,int  age  ,  char*  no);
getName()
{ cout<<name;}
getAge()
{ cout<<age;}
getNo()
{cout<<no;}

};

Student::Student(char*  na,int  ag  ,  char*  n)
{
name=new char [100];
int i=0;
while(na[i]!=0)
{
	name[i]=na[i];
	i++;
}
age=ag;
no=new char [100];
while(n[i]!=0)
{
	no[i]=n[i];
	i++;
}
}

int  main()
{
        char  name[20];
        int  age;
        char  no[20];
        cin  >>  name  >>  age  >>  no;
        Student  stu(name,  age,  no);
        cout<<"Name:"<<stu.getName()<<"  Age:"<<stu.getAge()<<"  No:"<<stu.getNo()<<"\n";
        return  0;
}
