#include<iostream>
using namespace std;
class Poem
{
public:
	Poem();
	~Poem();
};
Poem::Poem()
{
	cout << "The most distant way in the world" << endl;
	cout << "is not the way from birth to the end" << endl;
}
Poem::~Poem()
{
	cout << "that you don't understand I love you." << endl;
}
int main()
{
	Poem Love;
	//定义一个对象
	cout << "It is when I sit near you" << endl;
	return 0;
}
