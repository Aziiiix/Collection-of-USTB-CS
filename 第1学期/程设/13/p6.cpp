#include<iostream>
#include"stdlib.h"
using  namespace  std;
const  int  length = 41;
class HugeInteger
{
private:
    int station[40] = { 0 };
    int size = 0;
public:
    HugeInteger();
    HugeInteger(const char* ori);
    void input(const char* ori);
    void output();
    HugeInteger add(const HugeInteger &obj);
};
HugeInteger::HugeInteger()
{}
HugeInteger::HugeInteger(const char* ori)
{
    for (int i = 0; i <= size; i++)
    {
        station[i] = ori[i];
    }
}
void HugeInteger::input(const char* ori)
{
    for (int i = 0; ori[i] != '\0'; i++)
    {
        station[i] = ori[i] - '0';
        size = i;
    }
    for (int i = size; i < 40; i++)
    {
        station[i] = 0;
    }
}
HugeInteger HugeInteger::add(const HugeInteger& obj)
{
    int ans[40] = { 0 };

}


int  main()
{
    HugeInteger  hi1;
    char* c = new  char[length];
    cin >> c;
    char* d = new  char[length];
    cin >> d;
    hi1.input(c);
    HugeInteger  hi2(d);
    (hi1.add(hi2)).output();
    return  0;
}
