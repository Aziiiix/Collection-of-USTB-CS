#include  <iostream>      //  ����ͷ�ļ�iostream
#include  <cstring>
using  namespace  std;    //  ʹ�������ռ�std
class  Car
{
public:
    //  ��Ա��������
    Car();
    Car(int pld, const char* pBrand, float  pPower, int  pNumOfPersons);
    void printCar();
    void setId(int pld);
    ~Car();
    Car(Car& car);

private:
    int  id;
    char* brand;
    float  power;
    int  numOfPersons;
};
Car::Car()
{
    cout << "Constructed  without  any  parameter." << endl;
}
Car::Car(int  pId, const  char* pBrand, float  pPower, int  pNumOfPersons)
{
    id = pId;
    brand=new char[strlen(pBrand)+1];
    if(brand!=0)strcpy(brand,pBrand);
    power = pPower;
    numOfPersons = pNumOfPersons;
    cout << "Constructed  with  all  parameters." << endl;
}
Car::Car(Car& car)
{
    id = car.id;
    brand=new char[strlen(car.brand)+1];
    if(brand!=0) strcpy(brand,car.brand);
    power = car.power;
    numOfPersons = car.numOfPersons;
    cout << "Deep  Constucted." << endl;
}
Car::~Car()
{
    delete[]  brand;
    cout << "Deconstructed." << endl;
}
void  Car::printCar()
{
    cout << "id:  " << id << ",  "
        << "brand:  " << brand << ",  "
        << "power:  " << power << ",  "
        << "numOfPersons:  " << numOfPersons << endl;
}
void  Car::setId(int  pId)
{
    id = pId;
}
int  main()
{
    Car  car1(1001, "Toyota", 1.8f, 5);
    Car  car2(car1);
    car2.setId(1002);
    Car  car3=car1;
    car3.setId(1003);
    car1.printCar();
    car2.printCar();
    car3.printCar();
    return  0;
}
