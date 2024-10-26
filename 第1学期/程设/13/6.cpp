#include<iostream>
using namespace std;
class Dog
{
	public:
		Dog(int pAge=0,int pWeight=0)
		{
			age=pAge;
			weight=pWeight;
		}
		int GetAge(){return age;}
		void SetAge(int pAge){age=pAge;}
		int GetWeight(){return weight;}
		void SetWeight(int pWeight){weight=pWeight;}
	private:
		int age;
		int weight;
};
int main()
{
	Dog jack;
	jack.SetAge(2);
	jack.SetWeight(10);
	cout<<jack.GetAge()<<" "<<jack.GetWeight()<<endl;
	jack.SetAge(30);
	jack.SetWeight(10);
	cout<<jack.GetAge()<<" "<<jack.GetWeight()<<endl;
	return 0;
}


