#include<iostream>
using namespace std;
class Vehicle
{
public:
	Vehicle(int ps, int pt) :wheels(ps), weight(pt) {};
	int getWheels() { return wheels; }
	int getWeight() { return weight; }
private:
	int wheels;
	int weight;
};
class Car :public Vehicle
{
public:
	Car(int ps, int pt, int pd) :Vehicle(ps ,pt), passenger_load(pd) {};
	int getPassenger() { return passenger_load; }
private:
	int passenger_load;
};
class Truck :public Vehicle
{
public:
	Truck(int ps, int pt, int psd, int pad) :Vehicle(ps, pt), passenger_load(psd), payload(pad) {};
	int getPassenger() { return passenger_load; }
	int getPayload() { return payload; }
private:
	int passenger_load;
	int payload;
};
int main()
{
	Vehicle V(8, 5);
	cout << "vehicle:" << endl;
	cout << "the number of cartwheel:" << V.getWheels() << endl;
	cout << "weight:" << V.getWeight() << "ton" << endl;
	Car C(4, 1, 5);
	cout << "car:" << endl;
	cout << "the number of cartwheel:" << C.getWheels() << endl;
	cout << "weight:" << C.getWeight() << "ton" << endl;
	cout << "the number of available:" << C.getPassenger() << endl;
	Truck T(6, 8, 2, 10);
	cout << "truck:" << endl;
	cout << "the number of cartwheel:" << T.getWheels() << endl;
	cout << "weight:" << T.getWeight() << "ton" << endl;
	cout << "the number of available:" << T.getPassenger() << endl;
	cout << "load:" << T.getPayload() << "ton" << endl;
	return 0;
}
