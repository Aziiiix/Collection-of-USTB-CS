#include<iostream>
using  namespace  std;
class  vehicle  //����������
{
private:
        int  wh;  //������
        float  we;  //����
public:
	vehicle(int wheels,float weight):wh(wheels),we(weight){};
	void print()
	{
		cout<<"������Ϊ��"<<wh<<"��"<<endl;
		cout<<"����Ϊ��"<<we<<"��"<<endl; 
	}

};
class  car:public  vehicle  //��������С����
{
        int  pa;
    public:
    	car(int wheels,float weight,int person):vehicle(wheels,weight),pa(person){};
    	void print()
    	{
    		cout<<"С����"<<endl;
    		vehicle::print();
    		cout<<"������Ϊ��"<<pa<<"��"<<endl; 
		}

};
class  truck:public  vehicle  //��������������
{
        int  pa;
        float  pay;
    public:
    	truck(int wheels,float weight,int person,float load):vehicle(wheels,weight),pa(person),pay(load){};
    	void print()
    	{
    		cout<<"����"<<endl;
    		vehicle::print();
    		cout<<"������Ϊ��"<<pa<<"��"<<endl<<"����Ϊ"<<pay<<"��"<<endl; 
		}

};

int  main()
{
        int  vWH;
        float  vWE;
        cin  >>  vWH  >>  vWE;
        vehicle  ve1(vWH,vWE);
        ve1.print();
        int  cPA;
        cin  >>  vWH  >>  vWE  >>  cPA;
        car  car1(vWH,vWE,cPA);
        car1.print();
        double  tPay;
        cin  >>  vWH  >>  vWE  >>  cPA  >>  tPay;
        truck  tr1(vWH,vWE,cPA,tPay);
        tr1.print();
        return  0;
}
