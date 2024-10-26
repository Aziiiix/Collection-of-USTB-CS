#include <iostream>
using namespace std;
void f4(char a);
int main ()
{
    char myChar;
    cout<<"Enter a character:";
    cin>>myChar;
    f4(myChar);
    return 0;
}
void f4(char a)
{
    cout<<"\nYou just entered the character : "<<a<<endl;
}
