#include <cstring>
#include <math.h>

typedef char tcad[30];

typedef struct tvalor *pvalor;
struct tvalor
{
    tcad variable;
    float valor;
    pvalor sig;
};

struct tlistaValor
{
    pvalor inicio;
    pvalor final;
    int contador;
};

struct variablesAuxiliares
{
    tcad variable;
    float valor = -999999;
    bool existe = false;
};

class PruebaEscritori
{
private:
    /* data */
    void agregarFinal(tlistaValor &lista, pvalor nuevo);
    void iniciaListaValor(tlistaValor &tlista);
    void crearValor(pvalor &nuevo, tlistaValor &lista);
    float buscarUltimoValor(tlistaValor lista, tcad variable);
    void mostrar(tlistaValor lista, int opcion);
    void mostrarMostrarAuxOpDos(variablesAuxiliares varAux[], int ultimo);
    void mostrarMostrarAuxOpDosPositivo(variablesAuxiliares varAux[], int ultimo, int n);
    void mostrarMostrarAuxOpDosNegativo(variablesAuxiliares varAux[], int ultimo, int n);
    void mostrarBorrarAuxOpDos(variablesAuxiliares varAux[], tcad variables[], int ultimo);
    void limpiarListaValor(tlistaValor &lista);
    void sumarVariable(tlistaValor &lista, pvalor &nuevo);
    void restarVariable(tlistaValor &lista, pvalor &nuevo);
    void multiplicarVariable(tlistaValor &lista, pvalor &nuevo);
    void dividirVariable(tlistaValor &lista, pvalor &nuevo);
    void modVariable(tlistaValor &lista, pvalor &nuevo);
    void potenciaVariable(tlistaValor &lista, pvalor &nuevo);

public:
    PruebaEscritori(/* args */);
    ~PruebaEscritori();
    void iniciar();
};

PruebaEscritori::PruebaEscritori(/* args */)
{
}

PruebaEscritori::~PruebaEscritori()
{
}

void PruebaEscritori::agregarFinal(tlistaValor &lista, pvalor nuevo)
{
    if (lista.inicio == NULL)
    {
        lista.inicio = nuevo;
        lista.final = nuevo;
    }
    else
    {
        lista.final->sig = nuevo;
        lista.final = nuevo;
    }
    lista.contador = lista.contador++;
}

float PruebaEscritori::buscarUltimoValor(tlistaValor lista, tcad variable)
{
    pvalor i;
    float encontrado;
    if (lista.inicio != NULL)
        for (i = lista.inicio; i != NULL; i = i->sig)
            if (strcmp(i->variable, variable) == 0)
                encontrado = i->valor;
    return encontrado;
}

void PruebaEscritori::crearValor(pvalor &nuevo, tlistaValor &lista)
{
    nuevo = new tvalor;
    if (nuevo != NULL)
    {
        cout << "Ingrese variable: ";
        cin >> nuevo->variable;
        if (lista.final != NULL)
        {
            cout << "ultimo valor: " << buscarUltimoValor(lista, nuevo->variable) << endl;
        }

        cout << "Ingrese valor de " << nuevo->variable << ": ";
        cin >> nuevo->valor;
        nuevo->sig = NULL;
    }
    else
        cout << "MEMORIA INSUFICIENTE" << endl;
}

void PruebaEscritori::mostrarMostrarAuxOpDosNegativo(variablesAuxiliares varAux[], int ultimo, int n)
{

    if (varAux[n].valor <= -10 && varAux[n].valor > -100)
    {
        cout << varAux[n].valor << "      ";
    }
    else
    {
        if (varAux[n].valor <= -100 && varAux[n].valor > -1000)
        {
            cout << varAux[n].valor << "     ";
        }
        else
        {
            if (varAux[n].valor <= -1000 && varAux[n].valor > -10000)
            {
                cout << varAux[n].valor << "    ";
            }
            else
            {
                if (varAux[n].valor <= -10000 && varAux[n].valor > -100000)
                {
                    cout << varAux[n].valor << "   ";
                }
                else
                {
                    cout << varAux[n].valor << "  ";
                }
            }
        }
    }
}

void PruebaEscritori::mostrarMostrarAuxOpDosPositivo(variablesAuxiliares varAux[], int ultimo, int n)
{

    if (varAux[n].valor >= 10 && varAux[n].valor < 100)
    {
        cout << varAux[n].valor << "      ";
    }
    else
    {
        if (varAux[n].valor >= 100 && varAux[n].valor < 1000)
        {
            cout << varAux[n].valor << "     ";
        }
        else
        {
            if (varAux[n].valor >= 1000 && varAux[n].valor < 10000)
            {
                cout << varAux[n].valor << "    ";
            }
            else
            {
                if (varAux[n].valor >= 10000 && varAux[n].valor < 100000)
                {
                    cout << varAux[n].valor << "   ";
                }
                else
                {
                    cout << varAux[n].valor << "  ";
                }
            }
        }
    }
}

void PruebaEscritori::mostrarMostrarAuxOpDos(variablesAuxiliares varAux[], int ultimo)
{
    //imprimir
    for (int n = 0; n < ultimo; n++)
    {
        if (varAux[n].valor == -999999)
        {
            cout << "-"
                 << "      ";
        }
        else
        {
            if (varAux[n].valor >= 0)
            {
                if (varAux[n].valor < 10 && varAux->valor >= 0)
                {
                    cout << varAux[n].valor << "       ";
                }
                else
                {
                    mostrarMostrarAuxOpDosPositivo(varAux, ultimo, n);
                }
            }
            else
            {
                if (varAux[n].valor > -10 && varAux->valor < 0)
                {
                    cout << varAux[n].valor << "       ";
                }
                else
                {
                    mostrarMostrarAuxOpDosNegativo(varAux, ultimo, n);
                }
            }
        }
    }
    cout << endl;
}

void PruebaEscritori::mostrarBorrarAuxOpDos(variablesAuxiliares varAux[], tcad variables[], int ultimo)
{
    //borrar varAux
    for (int m = 0; m < ultimo; m++)
    {

        strcpy(varAux[m].variable, variables[m]);
        varAux[m].valor = -999999;
        varAux[m].existe = false;
    }
}

void PruebaEscritori::mostrar(tlistaValor lista, int opcion)
{
    pvalor i = NULL, auxValor = NULL, k = NULL;
    int ultimo;
    tcad variables[20], variableAnterior;
    float valores[20];
    bool banderaJ;
    if (lista.inicio != NULL)
    {
        ultimo = 0;
        for (i = lista.inicio; i != NULL; i = i->sig)
        {
            if (opcion == 3)
            {
                cout << i->variable << "= " << i->valor << endl;
            }
            else
            {
                banderaJ = false;
                for (int j = 0; j < ultimo; j++)
                {
                    if (ultimo != 0)
                    {
                        if (strcmp(variables[j], i->variable) == 0)
                        {
                            banderaJ = true;
                        }
                    }
                }
                if (banderaJ == false)
                {
                    strcpy(variables[ultimo], i->variable);
                    ultimo++;
                }
            }
        }
        if (opcion == 1)
        {
            cout << "-----------------------------" << endl;
            cout << "............................." << endl;
            for (int x = 0; x < ultimo; x++)
            {
                for (auxValor = lista.inicio; auxValor != NULL; auxValor = auxValor->sig)
                {
                    if (strcmp(variables[x], auxValor->variable) == 0)
                    {
                        valores[x] = auxValor->valor;
                    }
                }
                cout << "Variable " << x << ": " << variables[x] << "= " << valores[x] << endl;
            }
            cout << "............................." << endl;
            cout << "-----------------------------" << endl;
        }
        else
        {
            if (opcion == 2)
            {
                bool esPrimeroOpDos = true;
                variablesAuxiliares varAux[ultimo];

                for (auxValor = lista.inicio; auxValor != NULL; auxValor = auxValor->sig)
                {
                    if (esPrimeroOpDos)
                    {
                        mostrarBorrarAuxOpDos(varAux, variables, ultimo);

                        //imprimir variables (encabezado)
                        for (int l = 0; l < ultimo; l++)
                        {
                            cout << varAux[l].variable << "       ";
                        }
                        cout << endl;

                        esPrimeroOpDos = false;
                    }

                    for (int v = 0; v < ultimo; v++)
                    {
                        if (strcmp(varAux[v].variable, auxValor->variable) == 0)
                        {
                            if (!varAux[v].existe)
                            {
                                varAux[v].valor = auxValor->valor;
                                varAux[v].existe = true;
                            }
                            else
                            {
                                mostrarMostrarAuxOpDos(varAux, ultimo);
                                mostrarBorrarAuxOpDos(varAux, variables, ultimo);
                                varAux[v].valor = auxValor->valor;
                                varAux[v].existe = true;
                            }
                        }
                    }
                }
                mostrarMostrarAuxOpDos(varAux, ultimo);
                mostrarBorrarAuxOpDos(varAux, variables, ultimo);
            }
        }
    }
    else
    {
        cout << "LISTA VACIA" << endl;
    }
}

void PruebaEscritori::sumarVariable(tlistaValor &lista, pvalor &nuevo)
{
    nuevo = new tvalor;
    tcad variableOperacion;
    if (nuevo != NULL)
    {
        cout << "Ingrese variable: ";
        cin >> nuevo->variable;
        if (lista.final != NULL)
        {
            cout << "ultimo valor: " << buscarUltimoValor(lista, nuevo->variable) << endl;
        }

        cout << "Ingrese variable a sumar " << nuevo->variable << ": ";
        cin >> variableOperacion;
        nuevo->valor = buscarUltimoValor(lista, nuevo->variable) + buscarUltimoValor(lista, variableOperacion);
        nuevo->sig = NULL;
    }
    else
        cout << "MEMORIA INSUFICIENTE" << endl;
    agregarFinal(lista, nuevo);
}

void PruebaEscritori::restarVariable(tlistaValor &lista, pvalor &nuevo)
{
    nuevo = new tvalor;
    tcad variableOperacion;
    if (nuevo != NULL)
    {
        cout << "Ingrese variable: ";
        cin >> nuevo->variable;
        if (lista.final != NULL)
        {
            cout << "ultimo valor: " << buscarUltimoValor(lista, nuevo->variable) << endl;
        }

        cout << "Ingrese variable a restar " << nuevo->variable << ": ";
        cin >> variableOperacion;
        nuevo->valor = buscarUltimoValor(lista, nuevo->variable) - buscarUltimoValor(lista, variableOperacion);
        nuevo->sig = NULL;
    }
    else
        cout << "MEMORIA INSUFICIENTE" << endl;
    agregarFinal(lista, nuevo);
}

void PruebaEscritori::multiplicarVariable(tlistaValor &lista, pvalor &nuevo)
{
    nuevo = new tvalor;
    tcad variableOperacion;
    if (nuevo != NULL)
    {
        cout << "Ingrese variable: ";
        cin >> nuevo->variable;
        if (lista.final != NULL)
        {
            cout << "ultimo valor: " << buscarUltimoValor(lista, nuevo->variable) << endl;
        }

        cout << "Ingrese variable a multiplicar " << nuevo->variable << ": ";
        cin >> variableOperacion;
        nuevo->valor = buscarUltimoValor(lista, nuevo->variable) * buscarUltimoValor(lista, variableOperacion);
        nuevo->sig = NULL;
    }
    else
        cout << "MEMORIA INSUFICIENTE" << endl;
    agregarFinal(lista, nuevo);
}

void PruebaEscritori::dividirVariable(tlistaValor &lista, pvalor &nuevo)
{
    nuevo = new tvalor;
    tcad variableOperacion;
    if (nuevo != NULL)
    {
        cout << "Ingrese variable: ";
        cin >> nuevo->variable;
        if (lista.final != NULL)
        {
            cout << "ultimo valor: " << buscarUltimoValor(lista, nuevo->variable) << endl;
        }

        cout << "Ingrese variable a dividir " << nuevo->variable << ": ";
        cin >> variableOperacion;
        nuevo->valor = buscarUltimoValor(lista, nuevo->variable) / buscarUltimoValor(lista, variableOperacion);
        nuevo->sig = NULL;
    }
    else
        cout << "MEMORIA INSUFICIENTE" << endl;
    agregarFinal(lista, nuevo);
}

void PruebaEscritori::modVariable(tlistaValor &lista, pvalor &nuevo)
{
    nuevo = new tvalor;
    tcad variableOperacion;
    int variable1, variable2;
    if (nuevo != NULL)
    {
        cout << "Ingrese variable: ";
        cin >> nuevo->variable;
        if (lista.final != NULL)
        {
            cout << "ultimo valor: " << buscarUltimoValor(lista, nuevo->variable) << endl;
        }

        cout << "Ingrese variable a mod " << nuevo->variable << ": ";
        cin >> variableOperacion;
        variable1 = buscarUltimoValor(lista, nuevo->variable);
        variable2 = buscarUltimoValor(lista, variableOperacion);
        nuevo->valor = variable1 % variable2;
        nuevo->sig = NULL;
    }
    else
        cout << "MEMORIA INSUFICIENTE" << endl;
    agregarFinal(lista, nuevo);
}

void PruebaEscritori::potenciaVariable(tlistaValor &lista, pvalor &nuevo)
{
    nuevo = new tvalor;
    tcad variableOperacion;
    if (nuevo != NULL)
    {
        cout << "Ingrese variable: ";
        cin >> nuevo->variable;
        if (lista.final != NULL)
        {
            cout << "ultimo valor: " << buscarUltimoValor(lista, nuevo->variable) << endl;
        }

        cout << "Ingrese variable a potenciar " << nuevo->variable << ": ";
        cin >> variableOperacion;
        nuevo->valor = pow(buscarUltimoValor(lista, nuevo->variable), buscarUltimoValor(lista, variableOperacion));
        nuevo->sig = NULL;
    }
    else
        cout << "MEMORIA INSUFICIENTE" << endl;
    agregarFinal(lista, nuevo);
}

void PruebaEscritori::limpiarListaValor(tlistaValor &lista)
{
    pvalor val, i;
    int maxValor = lista.contador;
    for (int j = 0; j < maxValor; j++)
    {
        do
        {
            if (lista.inicio == NULL)
            {
                val = NULL;
                delete (val);
            }
            else
            {
                if (lista.inicio == lista.final)
                {
                    val = lista.inicio;
                    lista.inicio = NULL;
                    lista.final = NULL;
                }
                else
                {
                    for (i = lista.inicio; (i->sig)->sig != lista.final; i = i->sig)
                        ;
                    val = lista.final;
                    lista.final = i;
                    lista.final->sig = NULL;
                }
                delete (val);
                lista.contador--;
            }
        } while (lista.contador != 0);
    }
}

void PruebaEscritori::iniciaListaValor(tlistaValor &tlista)
{
    tlista.inicio = NULL;
    tlista.final = NULL;
    tlista.contador = 0;
}

void PruebaEscritori::iniciar()
{
    int opcion = 1;
    tlistaValor lista;
    pvalor nuevo;

    iniciaListaValor(lista);

    do
    {
        crearValor(nuevo, lista);
        agregarFinal(lista, nuevo);
        do
        {
            do
            {
                mostrar(lista, 1);
                cout << "Desea agregar un nuevo valor? 0:NO   1:SI   2:Mostrar_Todo   3:Mostrar_Por_Ingreso " << endl
                     << "                              4:Sumar_otra_variable   5:Restar_otra_variable " << endl
                     << "                              6:Multiplicar_otra_variable   7:Dividir_otra_variable " << endl
                     << "                              8:MOD_otra_variable   9:potencia_otra_variable " << endl;
                cin >> opcion;
                if (opcion == 2 || opcion == 3)
                {
                    mostrar(lista, opcion);
                }
                else
                {
                    switch (opcion)
                    {
                    case 4:
                        sumarVariable(lista, nuevo);
                        break;
                    case 5:
                        restarVariable(lista, nuevo);
                        break;
                    case 6:
                        multiplicarVariable(lista, nuevo);
                        break;
                    case 7:
                        dividirVariable(lista, nuevo);
                        break;
                    case 8:
                        modVariable(lista, nuevo);
                        break;
                    case 9:
                        potenciaVariable(lista, nuevo);
                        break;
                    }
                }
            } while (opcion != 0 && opcion != 1);
        } while (opcion != 0 && opcion != 1 && opcion != 2 && opcion != 3);
    } while (opcion != 0);
    cout << "-----------------------------" << endl;
    mostrar(lista, 1);
    cout << "-----------------------------" << endl;
    mostrar(lista, 2);
    cout << "-----------------------------" << endl;

    limpiarListaValor(lista);
}