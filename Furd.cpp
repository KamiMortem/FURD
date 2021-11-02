#include <iostream>
#include <stdlib.h>
#include "Hora.hpp"
#include "Algebraico.hpp"
#include "PruebaEscritori.hpp"

using namespace std;

typedef char tcad[30];

void pruebaDeEscritorio()
{
    PruebaEscritori pruebaEsc;
    pruebaEsc.iniciar();
}

void obtenerNumeroAleatorio()
{
    int max, numRandom;
    srand((unsigned)time(0));
    cout << "Ingrese un valor maximo" << endl;
    cin >> max;
    cout << endl;
    numRandom = (rand() % max) + 1;
    cout << "El numero random entre 1 y " << max << " es:" << numRandom << endl
         << endl;
}

Hora insertarHora(tcad mensaje)
{
    int hora1, minuto1, segundo1;
    cout << endl
         << "* Ingrese Primero hora, luego minuto y al final segundo. Si quiere ingresarlo en una sola linea, separelos con un +" << endl
         << endl;
    cout << mensaje << endl;
    cin >> hora1;
    do
    {
        cin >> minuto1;
    } while (minuto1 > 60);
    do
    {
        cin >> segundo1;
    } while (segundo1 > 60);

    cout << endl
         << "Inserto la Hora: " << hora1 << ":" << minuto1 << ":" << segundo1 << endl
         << endl;
    Hora horaAux(hora1, minuto1, segundo1);
    return horaAux;
}

void dividirHoras()
{
    tcad msj = "Ingrese la hora a dividir";
    Hora horaDividir = insertarHora(msj);
    int divisor;
    cout << "Ingrese la cantidad de veces que lo quiere dividir: ";
    cin >> divisor;
    horaDividir = horaDividir.dividirHora(divisor);
    cout << "El resultado es:" << endl;
    cout << " " << horaDividir.getHora() << ":" << horaDividir.getMinutos() << ":" << horaDividir.getSegundos() << endl;
}

void sumarRestarHora(bool sumar)
{
    tcad msj = "Inserte la 1era hora";
    Hora horaDia = insertarHora(msj);
    tcad msj1 = "Inserte la 2da hora";
    Hora horaAux = insertarHora(msj1);

    cout << "La operacion de: " << horaDia.getHora() << ":" << horaDia.getMinutos() << ":" << horaDia.getSegundos()
         << " y " << horaAux.getHora() << ":" << horaAux.getMinutos() << ":" << horaAux.getSegundos() << endl;

    if (sumar)
    {
        horaAux = horaDia.sumarHora(horaAux);
        cout << "su suma es: ";
    }
    else
    {
        horaAux = horaDia.restarHora(horaAux);
        cout << "su resta es: ";
    }

    cout << " " << horaAux.getHora() << ":" << horaAux.getMinutos() << ":" << horaAux.getSegundos() << endl;
}

void reglaTresInversa()
{
    Algebraico alg;
    alg.reglaDeTresInversa();
}

void reglaTresSimple()
{
    Algebraico alg;
    alg.reglaDeTresSimple();
}

/* Menu principal */
int menu(int &opcion)
{
    cout << "-----------------------------------------------------------------" << endl;
    cout << "1- Dividir hora" << endl;
    cout << "2- Sumar Horas" << endl;
    cout << "3- Restar Horas" << endl;
    cout << "4- Regla de 3 simples" << endl;
    cout << "5- Regla de 3 inversa" << endl;
    cout << "7- Obtener numero random" << endl;
    cout << "8- Prueba de escritorio" << endl;
    cout << "10- Salir" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cin >> opcion;
    return opcion;
}

int main(int argc, char *argv[])
{
    int opcion;

    do
    {
        switch (menu(opcion))
        {
        case 1:
            dividirHoras();
            break;
        case 2:
            sumarRestarHora(true);
            break;
        case 3:
            sumarRestarHora(false);
            break;
        case 4:
            reglaTresSimple();
            break;
        case 5:
            reglaTresInversa();
            break;
        case 7:
            obtenerNumeroAleatorio();
            break;
        case 8:
            pruebaDeEscritorio();
            break;
        case 10:
            cout << "Gracias por usar el programa" << endl;
            break;
        default:
            cout << "Se equivoco de comando, escribalo nuevamente" << endl;
            break;
        }
    } while (opcion != 10);
}