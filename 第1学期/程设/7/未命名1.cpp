//code by Aziiii
#include<iostream>
using namespace std;
struct  Person {
    char  name[20];
    long  id;
    float  salary;
};
Person  allone[6] = { {"jone",12345,339.0},{"david",13916,449.0},{"marit",27519,311.0},
                                {"jasen",42876,623.0},{"peter",23987,400.0},{"yoke",12335,511.0} };
int  main()
{
    int temp;
    int  i, j;
    int index[6];

    for (int i = 0; i < 6; i++)
    {
        index[i] = i;
    }
    
    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < 6-i; j++)
        {
            if (allone[index[j]].salary > allone[index[j+1]].salary)
            {
                temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k < 6; k++) {
        cout << allone[index[k]].name << "  " << allone[index[k]].id << "  " << allone[index[k]].salary << endl;

    }

    return  0;
}
