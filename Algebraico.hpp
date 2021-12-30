#include <iostream>

using namespace std;

typedef char tcad[30];

class Algebraico
{
private:
     void reglaDeTresSimpleInversa(float &num1, float &num2, float &num3);
     void cargarVariablesEncontrarPosicion(tcad orden[], int &cantidad);
     void mostrarOrdenEncontrarPosicion(tcad orden[], int &cantidad);
     void cargarValoresEncontrarPosicion(tcad orden[], int &cantidad, int relaciones[100][100], int &cantidadRelaciones);
     int encontrarValorOrdenEncontrarPosicion(tcad orden[], int cantidad, tcad variable);
     void ordenarVariablesEncontrarPosicion(tcad orden[], int &cantidad, int relaciones[100][100], int &cantidadRelaciones, tcad ordenOrdenadas[]);
     void ordenarVariableUnaAUnaEncontrarPosicion(tcad orden[], int &cantidad, int relaciones[100][100], int numeroRelacion, tcad ordenOrdenadas[]);
     void mostrarRelacionesEncontrarPosicion(int relaciones[100][100], int cantidadRelaciones, tcad orden[], int cantidad);

public:
     Algebraico(/* args */);
     ~Algebraico();
     void reglaDeTresSimple();
     void reglaDeTresInversa();
     int mcm(int num1, int num2);
     int mcd(int num1, int num2);
     void encontrarPosicion();
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

int Algebraico::encontrarValorOrdenEncontrarPosicion(tcad orden[], int cantidad, tcad variable)
{
     int pos = -1;
     for (int i = 0; i < cantidad; i++)
     {
          if (strcmp(orden[i], variable) == 0)
          {
               pos = i;
               return pos;
          }
     }
     return pos;
}

void Algebraico::mostrarRelacionesEncontrarPosicion(int relaciones[100][100], int cantidadRelaciones, tcad orden[], int cantidad)
{
     char relacion;
     int var1;
     int var2;
     for (int i = 0; i < cantidadRelaciones; i++)
     {

          switch (relaciones[i][1])
          {
          case 1:
               relacion = '<';
               break;
          case 2:
               relacion = '=';
               break;
          case 3:
               relacion = '>';
               break;
          default:
               cout << "ingreso un valor no valido" << endl;
               break;
          }
          cout << "Relacion N°" << i << ": " << orden[relaciones[i][0]] << " " << relacion << " " << orden[relaciones[i][2]] << endl;
     }
}

void Algebraico::mostrarOrdenEncontrarPosicion(tcad orden[], int &cantidad)
{
     cout << "-------------------------------------------------------------------------------" << endl;
     for (int i = 0; i < cantidad; i++)
     {
          cout << "Posicion: " << i << " Variable: " << orden[i] << endl;
     }
     cout << "-------------------------------------------------------------------------------" << endl;
}

void Algebraico::cargarVariablesEncontrarPosicion(tcad orden[], int &cantidad)
{
     char opcion;

     do
     {
          tcad variable;
          cout << "Ingrese una variable: ";
          cin >> variable;
          cout << "Desea ingresar una nueva variable? s/n" << endl;
          cin >> opcion;
          strcpy(orden[cantidad], variable);
          cantidad++;
          mostrarOrdenEncontrarPosicion(orden, cantidad);
     } while (opcion != 'n' && opcion != 'N');
}

void Algebraico::cargarValoresEncontrarPosicion(tcad orden[], int &cantidad, int relaciones[100][100], int &cantidadRelaciones)
{
     char opcion;
     int posicion, posicion1;
     int relacion;
     tcad variable;
     tcad variable1;
     char relacionCaracter;
     do
     {
          mostrarRelacionesEncontrarPosicion(relaciones, cantidadRelaciones, orden, cantidad);
          mostrarOrdenEncontrarPosicion(orden, cantidad);
          do
          {
               posicion = -1;

               cout << "Ingrese una variable de la lista para la 1era relacion: ";
               cin >> variable;
               posicion = encontrarValorOrdenEncontrarPosicion(orden, cantidad, variable);
          } while (posicion == -1);

          do
          {
               posicion1 = -1;

               cout << "Ingrese una variable de la lista para la 2da relacion: ";
               cin >> variable1;
               posicion1 = encontrarValorOrdenEncontrarPosicion(orden, cantidad, variable1);
          } while (posicion1 == -1);

          do
          {
               cout << "Ingrese la relacion entre la 1era y 2da variable: " << endl;
               cout << " 1- '<'               2- '='               3- '>'" << endl;
               cin >> relacion;
               switch (relacion)
               {
               case 1:
                    relacionCaracter = '<';
                    break;
               case 2:
                    relacionCaracter = '=';
                    break;
               case 3:
                    relacionCaracter = '>';
                    break;
               default:
                    cout << "ingreso un valor no valido" << endl;
                    break;
               }

          } while (relacion != 1 && relacion != 2 && relacion != 3);

          relaciones[cantidadRelaciones][0] = posicion;
          relaciones[cantidadRelaciones][1] = relacion;
          relaciones[cantidadRelaciones][2] = posicion1;

          cantidadRelaciones++;
          cout << "Ingreso la siguiente relacion: " << variable << " " << relacionCaracter << " " << variable1 << endl;
          cout << "Desea ingresar una nueva relacion? s/n" << endl;
          cin >> opcion;
     } while (opcion != 'n' && opcion != 'N');
}

void Algebraico::ordenarVariableUnaAUnaEncontrarPosicion(tcad orden[], int &cantidad, int relaciones[100][100], int numeroRelacion, tcad ordenOrdenadas[])
{
     int posicion = relaciones[numeroRelacion][0];
     int relacion = relaciones[numeroRelacion][1];
     int posicion1 = relaciones[numeroRelacion][2];
     int posicionOrdenada = encontrarValorOrdenEncontrarPosicion(ordenOrdenadas, cantidad, orden[posicion]);
     int posicion1Ordenada = encontrarValorOrdenEncontrarPosicion(ordenOrdenadas, cantidad, orden[posicion1]);
     bool cambia = false;
     tcad valorMenor;
     tcad valorMayor;
     if (relacion == 1)
     {
          if (!(posicionOrdenada < posicion1Ordenada))
          {
               strcpy(valorMenor, ordenOrdenadas[posicion1Ordenada]);
               strcpy(valorMayor, ordenOrdenadas[posicionOrdenada]);
               cambia = true;
          }
     }
     if (relacion == 2)
     {
          if (!(posicionOrdenada + 1 == posicion1Ordenada || posicionOrdenada - 1 == posicion1Ordenada))
          {
               strcpy(valorMenor, ordenOrdenadas[posicion1Ordenada]);
               strcpy(valorMayor, ordenOrdenadas[posicionOrdenada]);
               cambia = true;
          }
     }
     if (relacion == 3)
     {
          if (!(posicionOrdenada > posicion1Ordenada))
          {
               strcpy(valorMayor, ordenOrdenadas[posicion1Ordenada]);
               strcpy(valorMenor, ordenOrdenadas[posicionOrdenada]);
               cambia = true;
          }
     }
     int posicionMenor = encontrarValorOrdenEncontrarPosicion(ordenOrdenadas, cantidad, valorMenor);
     int posicionMayor = encontrarValorOrdenEncontrarPosicion(ordenOrdenadas, cantidad, valorMayor);
     if (cambia)
     {
          for (int i = posicionMenor; i < posicionMayor; i++)
          {
               strcpy(ordenOrdenadas[i], ordenOrdenadas[i + 1]);
          }
          strcpy(ordenOrdenadas[posicionMayor], valorMenor);
          strcpy(ordenOrdenadas[posicionMayor - 1], valorMayor);
          cout << "Cambio algo" << endl;
     }
}

void Algebraico::ordenarVariablesEncontrarPosicion(tcad orden[], int &cantidad, int relaciones[100][100], int &cantidadRelaciones, tcad ordenOrdenadas[])
{
     for (int i = 0; i < cantidadRelaciones; i++)
     {
          ordenarVariableUnaAUnaEncontrarPosicion(orden, cantidad, relaciones, i, ordenOrdenadas);
     }
     /* for (int j = cantidadRelaciones; j >= 0; j--)
     {
          ordenarVariableUnaAUnaEncontrarPosicion(orden, cantidad, relaciones, j, ordenOrdenadas);
     }
     for (int k = 0; k < cantidadRelaciones; k++)
     {
          ordenarVariableUnaAUnaEncontrarPosicion(orden, cantidad, relaciones, k, ordenOrdenadas);
     } */
}

void Algebraico::encontrarPosicion()
{
     tcad orden[100];
     int relaciones[100][100];
     tcad ordenOrdenadas[100];
     int cantidad = 0;
     int cantidadRelaciones = 0;

     cargarVariablesEncontrarPosicion(orden, cantidad);
     cargarValoresEncontrarPosicion(orden, cantidad, relaciones, cantidadRelaciones);
     for (int i = 0; i < cantidad; i++)
     {
          strcpy(ordenOrdenadas[i], orden[i]);
     }
     ordenarVariablesEncontrarPosicion(orden, cantidad, relaciones, cantidadRelaciones, ordenOrdenadas);
     mostrarRelacionesEncontrarPosicion(relaciones, cantidadRelaciones, orden, cantidad);
     mostrarOrdenEncontrarPosicion(ordenOrdenadas, cantidad);
}