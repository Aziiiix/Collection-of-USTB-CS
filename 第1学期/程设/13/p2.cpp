
#include  <iostream>
using  namespace  std;
class  Sales_status
{
public:
        Sales_status(int  sId,    int  pq,  float  pprice);  //��������Ĵ������Ĺ��캯��
        ~Sales_status();
        static  float  printsum();
        static  float  average();          
private:
        int  num;
        int  quantity;
        float  price;
        static  float  discount;
        static  int  n;                                    //���徲̬��Ա������Ʒ�����ܼ�����n
        static  float  sum;                          //���徲̬��Ա������Ʒ�����ܽ�sum
};
Sales_status::Sales_status(int sId,int  pq,float  pprice)
{
	num=sId;pq=quantity;price=pprice;
}
//��ʼ����̬��Ա����
float Sales_status::discount=0.98;
int Sales_status::n=117;
float Sales_status::sum=23.5*5+24.56*12*discount+21.5*100*discount;

Sales_status::~Sales_status()
{
	//��֪��дɶ 
}
float  Sales_status::printsum()
{
    return  sum;
}
float  Sales_status::average()
{
    return  sum/n;
}
int  main()
{
    Sales_status  s1(101, 5, 23.5);
    Sales_status  s2(102, 12, 24.56);
    Sales_status  s3(103, 100, 21.5);
    cout<<"the  sum  is:"<<endl;
    //���þ�̬��Ա����
    cout<<s1.printsum()<<endl; 
    cout  <<  endl<<"the  average  price  is:"<<endl;
    //���þ�̬��Ա����
    cout<<s1.average()<<endl;
    return  0;
}
