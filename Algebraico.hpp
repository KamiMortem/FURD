#include <iostream>

using namespace std;

class Algebraico
{
private:
     void reglaDeTresSimpleInversa(float &num1, float &num2, float &num3);

public:
     Algebraico(/* args */);
     ~Algebraico();
     void reglaDeTresSimple();
     void reglaDeTresInversa();
     int mcm(int num1, int num2);
     int mcd(int num1, int num2);
};

Algebraico::Algebraico(/* args */)
{
}

Algebraico::~Algebraico()
{
}

void Algebraico::reglaDeTresSimpleInversa(float &num1, float &num2, float &num3)
{
     cout << "Inserte el 1er numero:";
     cin >> num1;
     cout << endl;
     cout << num1 << "     ->     "
          << "" << endl;
     cout << "  "
          << "     ->     "
          << "X" << endl;

     cout << "Inserte el 2do numero, que corresponde al 1ero:";
     cin >> num2;
     cout << endl;
     cout << num1 << "     ->     " << num2 << endl;
     cout << "  "
          << "     ->     "
          << "X" << endl;

     cout << "Inserte el 3er numero:";
     cin >> num3;
     cout << endl;
     cout << num1 << "     ->     " << num2 << endl;
     cout << num3 << "     ->     "
          << "X" << endl;
     cout << endl;
     cout << "El valor del 4to numero es:" << (num3 * num2) / num1 << endl;
     cout << num1 << "     ->     " << num2 << endl;
     cout << num3 << "     ->     ";
}

void Algebraico::reglaDeTresSimple()
{
     float num1, num2, num3;
     reglaDeTresSimpleInversa(num1, num2, num3);
     cout << "X=" << (num3 * num2) / num1 << endl;
}

void Algebraico::reglaDeTresInversa()
{
     float num1, num2, num3;
     reglaDeTresSimpleInversa(num1, num2, num3);
     cout << "X=" << (num1 * num2) / num3 << endl;
}

int Algebraico::mcd(int num1, int num2)
{
     int result = 0;
     int a = max(num1, num2);
     int b = min(num1, num2);
     do
     {
          result = b;
          b = a % b;
          a = result;
     } while (b != 0);
     return result;
}

int Algebraico::mcm(int num1, int num2)
{
     int result = 0;
     int a = max(num1, num2);
     int b = min(num1, num2);
     result = (a / mcd(a, b)) * b;
     return result;
}