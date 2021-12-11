#include <iostream>
#include <stdlib.h>
#include <limits>
#include <cstdlib>
#include <string>
#include <sstream>

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

void operacionesHoras()
{
    int opcion;
    cout << "Seleccione una opcion" << endl;
    cout << "1- Sumar Horas" << endl;
    cout << "2- Restar Horas" << endl;
    cout << "3- Dividir Horas entre un numero" << endl;
    cin >> opcion;
    cout << " " << endl;
    switch (opcion)
    {
    case 1:
        sumarRestarHora(true);
        break;
    case 2:
        sumarRestarHora(false);
        break;
    case 3:
        dividirHoras();
        break;
    default:
        break;
    }
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

void criptografia()
{
    cout << "En construccion, criptograficos" << endl;
}

void graficarFunciones()
{
    cout << "En construccion, la graficacion de funciones" << endl;
}

void opcionesInternet()
{
    int opcion;
    cout << "Seleccione una opcion" << endl;
    cout << "1- WiFi" << endl;
    cout << "2- IP publica" << endl;
    cout << "3- IP privada" << endl;
    cout << "4- Reiniciar servicio de internet" << endl;
    cout << "5- Ping Google" << endl;
    cin >> opcion;

    cout << " " << endl;

    switch (opcion)
    {
    case 1:
        system("nmtui");
        system("clear");
        break;
    case 2:
        system("curl ifconfig.me");
        cout << " " << endl;
        break;
    case 3:
        system("ip addr 2> /dev/null");
        cout << "------------------------------------------------------------------------------" << endl;
        system("ifconfig 2> /dev/null");
        break;
    case 4:
        system("sudo systemctl restart NetworkManager");
        break;
    case 5:
        system("ping www.google.com");
        break;
    default:
        break;
    }
    cout << " " << endl;
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

void reglaDeTres()
{
    int opcion;
    cout << "Seleccione una opcion" << endl;
    cout << "1- Regla de 3 SIMPLE" << endl;
    cout << "2- Regla de 3 INVERSA" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    if (opcion == 1)
        reglaTresSimple();
    if (opcion == 2)
        reglaTresInversa();
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

void sobrePC()
{
    cout << " " << endl;
    system("w");
    cout << " " << endl;
    system("neofetch");
}

void backup()
{
    cout << "En construccion " << endl;
}

void temporizador()
{
    int opcion, tiempo = 0;
    char unidad;
    string mensaje;
    cout << "Elija la unidad de tiempo que usara:" << endl;
    cout << "h / m / s ? : ";
    cin >> unidad;

    cin.ignore();
    cout << "Mensaje del temporizador: " << endl;
    getline(cin, mensaje);

    cout << "Defina el tiempo: " << endl;
    cin >> tiempo;
    if (unidad == 'h')
    {
        tiempo = tiempo * 60 * 60;
    }
    else
    {
        if (unidad == 'm')
        {
            tiempo = tiempo * 60;
        }
    }
    stringstream comando;
    comando << "sleep " << tiempo / 2 << " && notify-send -u normal -t 0 'Mitad de tiempo del temporisador' '" << mensaje << "' &";
    comando << "sleep " << tiempo << " && notify-send -u critical -t 0 'TERMINO el temporisador' '" << mensaje << "' &";
    system(comando.str().c_str());
}

void opcionesUtilesSistema()
{
    int opcion;
    cout << "Seleccione una opcion" << endl;
    cout << "1- Bashtop" << endl;
    cout << "2- AlsaMixer (audio)" << endl;
    cout << "3- Borrar cache" << endl;
    cout << "4- Iniciar dunst" << endl;
    cout << "5- temporizador" << endl;
    cout << "6- BackUp" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        system("bashtop");
        system("clear");
        break;
    case 2:
        system("alsamixer");
        system("clear");
        break;
    case 3:
        system("sudo pacman -Sc && yay -Sc");
        break;
    case 4:
        system("systemctl start --user dunst.service");
        break;
    case 5:
        temporizador();
        break;
    case 6:
        backup();
        break;
    default:
        break;
    }
}

void algebraico()
{
    int opcion;
    cout << "Seleccione una opcion" << endl;
    cout << "1- Regla de 3" << endl;
    cout << "2- Operaciones con horas" << endl;
    cout << "3- Obtener MCM y MCD" << endl;
    cout << "4- Graficar funciones" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        reglaDeTres();
        break;
    case 2:
        operacionesHoras();
        break;
    case 3:
        obtenerMCMyMCD();
        break;
    case 4:
        graficarFunciones();
        break;
    default:
        break;
    }
}

void notas()
{
    cout << "En construccion " << endl;
}

void operacionesSistema()
{
    cout << "En construccion " << endl;
}

void gestorArchivos()
{
    system("ranger");
    system("clear");
}

/* Menu principal */
int menu(int &opcion)
{
    try
    {
        cout << "-----------------------------------< FURD >------------------------------------" << endl;
        cout << "| 1- Terminal               6- Obtener numero random     11- Limpiar pantalla |" << endl;
        cout << "| 2- Opcion Internet        7- PRUEBA DE ESCRITORIO      12- Criptograficas   |" << endl;
        cout << "| 3- Actualizar sistema     8- Sobre PC y users          13- Notas            |" << endl;
        cout << "| 4- Gestor archivos        9- Opciones utiles           14- Operaciones Sis  |" << endl;
        cout << "| 5- Calculadora           10- Opciones Algebraicas      15- Salir            |" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
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
            system("/bin/bash");
            break;
        case 2:
            opcionesInternet();
            break;
        case 3:
            actualizarSistema();
            break;
        case 4:
            gestorArchivos();
            break;
        case 5:
            calculadora();
            break;
        case 6:
            obtenerNumeroAleatorio();
            break;
        case 7:
            pruebaDeEscritorio();
            break;
        case 8:
            sobrePC();
            break;
        case 9:
            opcionesUtilesSistema();
            break;
        case 10:
            algebraico();
            break;
        case 11:
            system("clear");
            break;
        case 12:
            criptografia();
            break;
        case 13:
            notas();
            break;
        case 14:
            operacionesSistema();
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