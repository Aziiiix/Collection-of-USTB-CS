#include<iostream>
using namespace std;
class Animal
{
	public:
		Animal(){
		};
		virtual void what()const=0;
};
class Cat:public Animal
{
	public:
		Cat(){
		};
		void what()const
		{
			cout<<"Cat"<<endl;
		}
};
class Leopard:public Animal
{
	public:
		Leopard(){};
		void what()const
		{
			cout<<"Leopard"<<endl;
		}
};
int main()
{
	Cat C;
	C.what();
	Leopard P;
	P.what();
}
