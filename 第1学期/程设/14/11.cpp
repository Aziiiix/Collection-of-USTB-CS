#include<iostream>
using namespace std;
class Bed
{
public:
};
class Sofa
{
public:
};
class SleeperSofa :public Bed, public Sofa
{
public:
	SleeperSofa()
	{
		cout << "Watching" << endl;
	}
	~SleeperSofa()
	{
		cout << "Sleeping" << endl;
	}
	void FoldOut()
	{
		cout << "Fold out" << endl;
	}
};
int main()
{
	SleeperSofa SS;
	SS.FoldOut();
	return 0;
}
