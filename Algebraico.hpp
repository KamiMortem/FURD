#include <iostream>

using namespace std;

class Algebraico
{
private:
    /* data */
public:
    Algebraico(/* args */);
    ~Algebraico();
    void reglaDeTresSimple();
};

Algebraico::Algebraico(/* args */)
{
}

Algebraico::~Algebraico()
{
}

void Algebraico::reglaDeTresSimple()
{
    float num1, num2, num3;
    cout << "Inserte el 1er numero:";
    cin >> num1;

    cout << num1 << "     ->     "
         << "" << endl;
    cout << "  "
         << "     ->     "
         << "X" << endl;

    cout << "Inserte el 2do numero, que corresponde al 1ero:";
    cin >> num2;

    cout << num1 << "     ->     " << num2 << endl;
    cout << "  "
         << "     ->     "
         << "X" << endl;

    cout << "Inserte el 3er numero:";
    cin >> num3;

    cout << num1 << "     ->     " << num2 << endl;
    cout << num3 << "     ->     "
         << "X" << endl;

    cout << "El valor del 4to numero es:" << (num3 * num2) / num1 << endl;
    cout << num1 << "     ->     " << num2 << endl;
    cout << num3 << "     ->     "
         << "X=" << (num3 * num2) / num1 << endl;
}