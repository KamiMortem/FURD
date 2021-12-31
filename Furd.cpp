#include <iostream>
#include <stdlib.h>
#include <limits>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>

#include "Hora.hpp"
#include "Algebraico.hpp"
#include "PruebaEscritori.hpp"
#include "Sistema.hpp"

using namespace std;

typedef char tcad[30];

void borrarMenus(int cant)
{
    for (int i = 0; i < cant; i++)
    {
        cout << "\e[A";
    }
}

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

/* Menu de operaciones de horas */
void operacionesHoras()
{
    int opcion;
    do
    {
        cout << "---------------------------< Seleccione una opcion >---------------------------" << endl;
        cout << "| 1- Sumar Horas                                                              |" << endl;
        cout << "| 2- Restar Horas                                                             |" << endl;
        cout << "| 3- Dividir Horas entre un numero                       15- Atras - 0        |" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Opcion: ";
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
        case 111:
            system("clear");
            break;
        default:
            break;
        }
    } while (opcion != 15 && opcion != 0 && opcion != 111);
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

void encontrarPosicion()
{
    Algebraico alg;
    alg.encontrarPosicion();
}

void escanearRed()
{
    string ip;
    stringstream comando, comando1;
    cout << "Ingrese la ip que desea escanear. Ej: 192.168.1.*" << endl;
    cin.ignore();
    cout << "IP: ";
    getline(cin, ip);
    comando << "nmap -sP " << ip;
    system(comando.str().c_str());
    comando1 << "nmap -F " << ip;
    system(comando1.str().c_str());
}

void agregarRedOculta()
{
    stringstream comando;
    string nombreRed, contraseniaRed, tarjetaRed;

    cout << "Ingrese nombre de la tarjeta de red: ";
    cin.ignore();
    getline(cin, tarjetaRed);

    cout << "Ingrese el nombre de la red: ";
    getline(cin, nombreRed);

    cout << "Ingrese la contraseña de la red: ";
    getline(cin, contraseniaRed);

    comando << "nmcli c add type wifi con-name " << nombreRed << " ifname " << tarjetaRed
            << " ssid '" << nombreRed << "' ; nmcli dev wifi connect '" << nombreRed << "' password " << contraseniaRed << " hidden yes";
    system(comando.str().c_str());
}

/* Menu de opciones de internet */
void opcionesInternet()
{
    int opcion;
    do
    {
        cout << "---------------------------< Seleccione una opcion >---------------------------" << endl;
        cout << "| 1- WiFi                   6- Test Internet                                  |" << endl;
        cout << "| 2- IP publica             7- Pedir ip                                       |" << endl;
        cout << "| 3- IP privada             8- Escanear red                                   |" << endl;
        cout << "| 4- Reiniciar int.         9- Agregar red oculta                             |" << endl;
        cout << "| 5- Ping Google                                         15- Atras - 0        |" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Opcion: ";
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
            system("ifconfig 2> /dev/null");
            cout << "------------------------------------------------------------------------------" << endl;
            system("ip addr 2> /dev/null");
            break;
        case 4:
            system("sudo systemctl restart NetworkManager");
            break;
        case 5:
            system("ping www.google.com");
            break;
        case 6:
            system("speedtest-cli");
            break;
        case 7:
            system("ip route");
            break;
        case 8:
            escanearRed();
            break;
        case 9:
            agregarRedOculta();
            break;
        case 111:
            system("clear");
            break;
        default:
            break;
        }
        cout << " " << endl;
    } while (opcion != 15 && opcion != 0 && opcion != 111);
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

/* Menu de regla de 3 */
void reglaDeTres()
{
    int opcion;
    do
    {
        cout << "---------------------------< Seleccione una opcion >---------------------------" << endl;
        cout << "| 1- Regla de 3 SIMPLE                                                        |" << endl;
        cout << "| 2- Regla de 3 INVERSA                                  15- Atras - 0        |" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            reglaTresSimple();
            break;
        case 2:
            reglaTresInversa();
            break;
        case 111:
            system("clear");
            break;
        default:
            break;
        }
    } while (opcion != 15 && opcion != 0 && opcion != 111);
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
    system("sensors");
    system("time");
    cout << " " << endl;
    system("free -lh");
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

void conectarSSH()
{
    string ip, usuario;
    stringstream comando;
    cout << "Ingrese el nombre de usuario: ";
    cin.ignore();
    getline(cin, usuario);
    cout << "Ingrese la ip o nombre de maquina: ";
    getline(cin, ip);

    comando << "ssh " << usuario << "@" << ip;
    system(comando.str().c_str());
}

/* Menu de opciones utiles */
void opcionesUtilesSistema()
{
    int opcion;
    do
    {
        cout << "---------------------------< Seleccione una opcion >---------------------------" << endl;
        cout << "| 1- Procesos               6- BackUp                    11- SSH              |" << endl;
        cout << "| 2- AlsaMixer (audio)      7- Iniciar dunst             12- elinks           |" << endl;
        cout << "| 3- History                8- Telegram-cli              13- cmus             |" << endl;
        cout << "| 4- Borrar cache           9- Calendario                                     |" << endl;
        cout << "| 5- temporizador          10- Clima                     15- Atras - 0        |" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("bashtop || htop || top");
            system("clear");
            break;
        case 2:
            system("alsamixer");
            system("clear");
            break;
        case 3:
            system("hstr");
            break;
        case 4:
            system("sudo pacman -Sc && yay -Sc");
            break;
        case 5:
            temporizador();
            break;
        case 6:
            backup();
            break;
        case 7:
            system("systemctl start --user dunst.service");
            break;
        case 8:
            system("telegram-cli");
            break;
        case 9:
            system("cal -y");
            system("date");
            break;
        case 10:
            system("curl -s wttr.in");
            system("curl -s wttr.in | head -n 7");
            break;
        case 11:
            conectarSSH();
            break;
        case 12:
            system("elinks");
            break;
        case 13:
            system("cmus");
            break;
        case 111:
            system("clear");
            break;
        default:
            break;
        }
    } while (opcion != 15 && opcion != 0 && opcion != 111);
}

/* Menu de opciones algebraicas */
void algebraico()
{
    int opcion;
    do
    {
        cout << "---------------------------< Seleccione una opcion >---------------------------" << endl;
        cout << "| 1- Regla de 3                                                               |" << endl;
        cout << "| 2- Operaciones con horas                                                    |" << endl;
        cout << "| 3- Obtener MCM y MCD                                                        |" << endl;
        cout << "| 4- Graficar funciones                                                       |" << endl;
        cout << "| 5- Encontrar posicion                                  15- Atras - 0        |" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
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
        case 5:
            encontrarPosicion();
            break;
        case 111:
            system("clear");
            break;
        default:
            break;
        }
    } while (opcion != 15 && opcion != 0 && opcion != 111);
}

void notas()
{
    cout << "En construccion " << endl;
}

void montarDisco()
{
    system("lsblk -fm");
}

/* Menu para reparar GRUB */
void repararGrub()
{
    int opcion;
    do
    {
        cout << "---------------------------< Seleccione una opcion >---------------------------" << endl;
        cout << "| 1- Arch UEFI                                                                |" << endl;
        cout << "| 2- Arch NO UEFI                                                             |" << endl;
        cout << "| 3- Debian UEFI                                                              |" << endl;
        cout << "| 4- Debian NO UEFI                                      15- Atras - 0        |" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("sudo grub-install --target=x86_64-efi --efi-directory=/boot/efi --bootloader-id=grub");
            system("sudo grub-mkconfig -o /boot/grub/grub.cfg");
            cout << "controla que exista la linea: GRUB_DISABLE_OS_PROBER=false" << endl;
            system("read ; sudo nano /etc/default/grub");
            system("sudo update-grub");
            system("sudo os-prober");
            break;
        case 2:
            system("");
            break;
        case 3:
            system("");
            break;
        case 4:
            system("");
            break;
        case 111:
            system("clear");
            break;
        default:
            break;
        }
    } while (opcion != 15 && opcion != 0 && opcion != 111);
}

/* Menu de operaciones del sistema */
void operacionesSistema()
{
    int opcion;
    do
    {
        cout << "---------------------------< Seleccione una opcion >---------------------------" << endl;
        cout << "| 1- Apagar PC              6- Reparar Grub                                   |" << endl;
        cout << "| 2- Reiniciar PC                                                             |" << endl;
        cout << "| 3- Suspender PC                                                             |" << endl;
        cout << "| 4- Informacion discos                                                       |" << endl;
        cout << "| 5- Montar discos                                       15- Atras - 0        |" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("sudo shutdown now");
            break;
        case 2:
            system("sudo shutdown -r now");
            break;
        case 3:
            system("echo 'suspender'");
            break;
        case 4:
            system("lsblk -fm");
            system("sudo fdisk -l");
            system("df -lh");
            break;
        case 5:
            montarDisco();
            break;
        case 6:
            repararGrub();
            break;
        case 111:
            system("clear");
            break;
        default:
            break;
        }
    } while (opcion != 15 && opcion != 0 && opcion != 111);
}

void gestorArchivos()
{
    system("ranger");
    system("clear");
}

void menuAyuda()
{
    cout << "La ayuda aun no esta disponible" << endl;
}

void instalarDependenciasAdicionales()
{
    cout << "Aqui se podra instalar las dependencias." << endl;
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
        cout << "| 5- Calculadora           10- Opciones Algebraicas      15- Salir - 0        |" << endl;
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

/* MAIN */
int main(int argc, char *argv[])
{
    int opcion;
    borrarMenus(1);
    do
    {
        switch (menu(opcion))
        {
        case 1:
            system("/bin/zsh 2> /dev/null || /bin/bash");
            break;
        case 2:
            borrarMenus(8);
            opcionesInternet();
            borrarMenus(10);
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
            borrarMenus(8);
            obtenerNumeroAleatorio();
            break;
        case 7:
            borrarMenus(8);
            pruebaDeEscritorio();
            borrarMenus(10);
            break;
        case 8:
            sobrePC();
            break;
        case 9:
            borrarMenus(8);
            opcionesUtilesSistema();
            borrarMenus(8);
            break;
        case 10:
            borrarMenus(8);
            algebraico();
            borrarMenus(8);
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
            borrarMenus(8);
            operacionesSistema();
            borrarMenus(8);
            break;
        case 15:
            cout << "Gracias por usar el programa" << endl;
            break;
        case 0:
            cout << "Gracias por usar el programa" << endl;
            break;
        case 111:
            cout << "Gracias por usar el programa" << endl;
            system("clear");
            break;
        case 999:
            instalarDependenciasAdicionales();
            break;
        case 911:
            menuAyuda();
            break;
        default:
            cout << "Se equivoco de comando, escribalo nuevamente" << endl;
            break;
        }
    } while (opcion != 15 && opcion != 0 && opcion != 111);
}