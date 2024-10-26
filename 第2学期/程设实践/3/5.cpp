#include<iostream>
using namespace std;

class PoweredDevice
{
public:
    static int Num_Power;
    PoweredDevice()
    {
        Num_Power++;
        cout << "A new PoweredDevice is constructed." << endl;
        cout << "There are " << Num_Power << " PoweredDevices in total." << endl;
    }
};

class Scanner :virtual public PoweredDevice
{
public:
    static int Num_Scan;
    Scanner()
    {
        Num_Scan++;
        cout << "A new Scanner is constructed." << endl;
        cout << "There are " << Num_Scan << " Scanner in total." << endl;
    }
};

class Printer :virtual public PoweredDevice
{
public:
    static int Num_Print;
    Printer()
    {
        Num_Print++;
        cout << "A new Printer is constructed." << endl;
        cout << "There are " << Num_Print << " Printer in total." << endl;
    }
};

class Copier :public Scanner, public Printer
{
public:
    static int Num_Cop;
    Copier()
    {
        Num_Cop++;
        cout << "A new Copier is constructed." << endl;
        cout << "There are " << Num_Cop << " Copiers in total." << endl;
    }
};

int PoweredDevice::Num_Power = 0;
int Scanner::Num_Scan = 0;
int Printer::Num_Print = 0;
int Copier::Num_Cop = 0;

int main()
{
    PoweredDevice** Group = new PoweredDevice * [100];
    int Fun[100];
    for (int i = 0; i < 100; i++)
    {
        char check; cin >> check;
        if (check == 's')
        {
            Group[i] = new Scanner;
            Fun[i] = 1;
        }
        if (check == 'p')
        {
            Group[i] = new Printer;
            Fun[i] = 3;
        }
        if (check == 'c')
        {
            Group[i] = new Copier;
            Fun[i] = 2;
        }
        if (check == 'e')
        {
            cout << "The devices are:" << endl;
            for (int j = 0; j < i; j++)
            {
                if (Fun[j] == 1)cout << "Scanner" << endl;
                else if (Fun[j] == 2)cout << "Copier" << endl;
                else if (Fun[j] == 3)cout << "Printer" << endl;
            }
            exit(0);
        }
    }
}
