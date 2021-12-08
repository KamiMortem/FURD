#include <iostream>
#include <stdlib.h>
#include <limits>
#include "Hora.hpp"
#include "Algebraico.hpp"
#include "PruebaEscritori.hpp"
#include "Sistema.hpp"

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
    do
    {
        try
        {
            cin >> max;
            if (!cin.good())
            {
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw 125;
            }
        }
        catch (int)
        {
            cout << "Ingreso un valor NO valido, ingrese nuevamente" << endl;
            max = -100;
        }
    } while (max < 0);
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
    do
    {
        try
        {
            cin >> hora1;
            if (!cin.good())
            {
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw 125;
            }
        }
        catch (int)
        {
            cout << "Ingreso un valor NO valido, ingrese nuevamente" << endl;
            hora1 = -100;
        }
    } while (hora1 < 0);

    do
    {
        try
        {
            cin >> minuto1;
            if (!cin.good())
            {
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw 125;
            }
        }
        catch (int)
        {
            cout << "Ingreso un valor NO valido, ingrese nuevamente" << endl;
            minuto1 = 100;
        }
    } while (minuto1 > 60);
    do
    {
        try
        {
            cin >> segundo1;
            if (!cin.good())
            {
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw 125;
            }
        }
        catch (int)
        {
            cout << "Ingreso un valor NO valido, ingrese nuevamente" << endl;
            segundo1 = 100;
        }
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
    if (!horaDividir.esCero())
    {
        cout << "El resultado es:" << endl;
        cout << " " << horaDividir.getHora() << ":" << horaDividir.getMinutos() << ":" << horaDividir.getSegundos() << endl;
    }
    else
        cout << "No se puede dividir por 0..." << endl;
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

void obtenerMCMyMCD()
{
    int num1, num2;
    Algebraico alg;
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << endl
         << "Ingrese el segundo numero: ";
    cin >> num2;
    cout << endl
         << "El MCD entre " << num1 << " y " << num2 << " es: " << alg.mcd(num1, num2) << endl;
    cout << "El MCM entre " << num1 << " y " << num2 << " es: " << alg.mcm(num1, num2) << endl;
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

void calculadora()
{
    Sistema sis;
    sis.calculadora();
}

void actualizarSistema()
{
    Sistema sis;
    sis.actualizarSistema();
}

/* Menu principal */
int menu(int &opcion)
{
    try
    {
        cout << "-----------------------------------< FURD >-----------------------------------" << endl;
        cout << " 1- Dividir hora          6- Obtener numero random     11- Limpiar pantalla " << endl;
        cout << " 2- Sumar horas           7- PRUEBA DE ESCRITORIO      12- Graficar Funciones " << endl;
        cout << " 3- Restar horas          8- Obtener el MCM y MCD      13- Criptograficas " << endl;
        cout << " 4- Regla de 3 simples    9- Actualizar sistema        14- " << endl;
        cout << " 5- Regla de 3 inversa   10- Calculadora del sistema   15- Salir " << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (!cin.good())
        {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw 125;
        }
    }
    catch (int)
    {
        cout << "Ingreso un valor NO valido" << endl;
        opcion = 0;
        return 0;
    }
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
        case 6:
            obtenerNumeroAleatorio();
            break;
        case 7:
            pruebaDeEscritorio();
            break;
        case 8:
            obtenerMCMyMCD();
            break;
        case 9:
            actualizarSistema();
            break;
        case 10:
            calculadora();
            break;
        case 11:
            system("clear");
            break;
        case 12:
            cout << "En construccion, la graficacion de funciones" << endl;
            break;
        case 13:
            cout << "En construccion, criptograficos" << endl;
            break;
        case 14:
            cout << "En construccion" << endl;
            break;
        case 15:
            cout << "Gracias por usar el programa" << endl;
            break;
        default:
            cout << "Se equivoco de comando, escribalo nuevamente" << endl;
            break;
        }
    } while (opcion != 15);
}