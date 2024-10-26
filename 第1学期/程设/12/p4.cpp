#include  <iostream>      //  包含头文件iostream
#include  <cstring>
using  namespace  std;
class Computer
{
public:
	Computer();
	~Computer();
	Computer(int  pId, char* pBrand, float  pMainFrequency, float  pHardDisk);
	Computer(const  Computer& Cp);
	void printComputer();
	void setId(int id);
	void setMainFrequency(float brand);
	void setHardDisk(float harddisk);
private:
	int id;
	char* brand;
	float mainFrequency;
	float hardDisk;
};

Computer::Computer()
{
	cout << "Constructed  without  any  parameter." << endl;
}
Computer::Computer(int  pId, char* pBrand, float  pMainFrequency, float  pHardDisk)
{

	id = pId;
	brand = new char[strlen(pBrand) + 1];
	if (brand != 0)strcpy(brand, pBrand);
	mainFrequency = pMainFrequency;
	hardDisk = pHardDisk;

	cout << "Constructed  with  all  parameters." << endl;
}
Computer::Computer(const  Computer& Cp)
{
	//  Computer复制构造函数的实现
	id = Cp.id;
	brand = new char[strlen(Cp.brand) + 1];
	if (brand != 0)strcpy(brand, Cp.brand);
	mainFrequency = Cp.mainFrequency;
	hardDisk = Cp.hardDisk;

	cout << "Copy  Constucted." << endl;
}
Computer::~Computer()
{

	brand[0] = '\0';
	delete[]brand;
	brand = 0;
	id = 0; mainFrequency = 0; hardDisk = 0;

	cout << "Deconstructed." << endl;
}

void Computer::setId(int Id)
{
	id = Id;
}
void Computer::setMainFrequency(float mainfrequency)
{
	mainFrequency = mainfrequency;
}
void Computer::setHardDisk(float harddisk)
{
	hardDisk = harddisk;
}

void  Computer::printComputer()
{
	cout << "id:  " << id << ",  "
		<< "brand:  " << brand << ",  "
		<< "mainFrequency:  " << mainFrequency << ",  "
		<< "hardDisk:  " << hardDisk << endl;
}
int  main()
{
	Computer  computer1(1001, "IBM", 1.8f, 500.f);
	Computer  computer2(computer1);
	computer2.setId(1002);
	computer2.setMainFrequency(2.f);
	computer2.setHardDisk(1000.f);
	Computer  computer3(computer1);
	computer3.setId(1003);
	computer3.setMainFrequency(2.5f);
	computer3.setHardDisk(1500.f);
	Computer  computer4 = computer1;
	computer4.setId(1004);
	computer4.setMainFrequency(2.f);
	computer4.setHardDisk(1200.f);
	computer1.printComputer();
	computer2.printComputer();
	computer3.printComputer();
	computer3.printComputer();
	computer4.printComputer();
	return  0;
}
