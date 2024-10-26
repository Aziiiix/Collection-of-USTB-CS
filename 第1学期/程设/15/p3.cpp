#include<iostream>
#include<string>
using  namespace  std;
class  Person {
protected:
    string  name;
    static  int  count;
    int  number;
    int  level;
    float  salary;
public:
    Person(string  name);
    string  GetName()
    {
        return  name;
    }
    int  GetNum() {
        return  number;
    }
    virtual  ~Person() {}
    virtual  float  MonthSalary() = 0;
    virtual  void  SetSales(float  sales) {}
    virtual  void  SetSumSales(float  sales) {}
};

class  Manager : public  Person {
public:
    Manager(string pname) :Person(pname)
    {
        number = count;
        level = 4;
        salary = 8000;
        count++;
    }
    float MonthSalary() { return salary; }
};

class  Partime_Technician : public  Person {
public:
    Partime_Technician(string pname) :Person(pname)
    {
        number = count;
        level = 3;
        salary = 8 * 100 * 20;
        count++;
    }
    float MonthSalary() { return salary; }
};

class  Sales_Manager : public  Person {
public:
    Sales_Manager(string pname, float sale) :Person(pname)
    {
        number = count;
        level = 3;
        salary = 5000;
        count++;
        SetSumSales(sale);
    }
    void SetSumSales(float sales)
    {
        smdx = sales;
        salary += (0.005 * smdx);
    }
    float MonthSalary() { return salary; }
private:
    float smdx;
};

class  Partime_Sales : public  Person {
public:
    Partime_Sales(string pname, float sum) :Person(pname)
    {
        number = count;
        level = 1;
        salary = 0;
        SetSumSales(sum);
        count++;
    }
    void  SetSumSales(float  sales)
    {
        smdx = sales;
        salary += (0.04 * smdx);
    }
    float MonthSalary() { return salary; }
private:
    float smdx;
};
int Person::count = 1;
Person::Person(string name)
{
    this->name=name;
}
int  main()
{
    int  numOfPersons;
    cout << "Input  the  number  of  persons:  " << endl;
    cin >> numOfPersons;
    Person** personArray = new  Person * [numOfPersons];
    int  i = 0;
    while (i < numOfPersons) {
        cout << "Input  the  person's  name:  " << endl;
        string  aName;
        cin >> aName;
        cout << "Input  the  person's  type:  " << endl;
        int  opt;
        cin >> opt;
        switch (opt) {
        case  1: {
            personArray[i] = new Manager(aName);
            i++;
            cout << "A  Manager  is  added." << endl;
            break;
        }
        case  2: {
            personArray[i] = new Partime_Technician(aName);
            i++;
            cout << "A  Partime_Technician  is  added." << endl;
            break;
        }
        case  3: {
            cout << "Input sum of sales:" << endl;
            int sumsales;
            cin >> sumsales;
            personArray[i] = new Sales_Manager(aName, sumsales);
            i++;
            cout << "A  Sales_Manager  is  added." << endl;
            break;
        }
        case  4: {
            cout << "Input his/her sales:" << endl;
            int sales;
            cin >> sales;
            personArray[i] = new Partime_Sales(aName, sales);
            i++;
            cout << "A  Partime_Sales  is  added." << endl;
            break;
        }
        }
    }
    cout << "The  persons  are:  " << endl;
    for (i = 0; i < numOfPersons; ++i) {
        cout << personArray[i]->GetNum() << " " << personArray[i]->GetName() << " " << personArray[i]->MonthSalary() << endl;
    }

    for (i = 0; i < numOfPersons; ++i) {
        delete personArray[i];
    }
    return  0;
}
