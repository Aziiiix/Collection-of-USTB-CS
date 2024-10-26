#include<iostream>
using namespace std;
class Animal
{
	public:
		Animal(){};
		void what()const
		{
			cout<<"..."<<endl;
		}
};
class Mouse:public Animal
{
	public:
		Mouse(){};
		void what()const
		{
			cout<<"zhi...zhi..."<<endl;
		}
};
class Dog:public Animal
{
	public:
		Dog(){};
		void what()const
		{
			cout<<"wang...wang..."<<endl;
		}
};
int main()
{
	Animal A;
	A.what();
	Mouse M;
	M.what();
	Dog D;
	D.what();
	return 0; 
}
