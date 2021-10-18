#include <cstring>

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

class PruebaEscritori
{
private:
    /* data */
    void agregarFinal(tlistaValor &lista, pvalor nuevo);
    void iniciaListaValor(tlistaValor &tlista);
    void crearValor(pvalor &nuevo, tlistaValor &lista);
    float buscarUltimoValor(tlistaValor lista, tcad variable);
    void mostrar(tlistaValor lista, int opcion);
    void limpiarListaValor(tlistaValor &lista);

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

void PruebaEscritori::mostrar(tlistaValor lista, int opcion)
{
    pvalor i = NULL, auxValor = NULL;
    int ultimo;
    tcad variables[20];
    float valores[20];
    bool banderaJ;
    if (lista.inicio != NULL)
    {
        ultimo = 0;
        for (i = lista.inicio; i != NULL; i = i->sig)
        {
            if (opcion == 2)
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
    }
    else
    {
        cout << "LISTA VACIA" << endl;
    }
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
                cout << "Desea agregar un nuevo valor?   0:NO   1:SI   2:Mostrar Todo" << endl;
                cin >> opcion;
                if (opcion == 2)
                {
                    mostrar(lista, 2);
                }
            } while (opcion != 0 && opcion != 1);
        } while (opcion != 0 && opcion != 1 && opcion != 2);
    } while (opcion != 0);
    cout << "-----------------------------" << endl;
    mostrar(lista, 1);
    cout << "-----------------------------" << endl;
    mostrar(lista, 2);
    cout << "-----------------------------" << endl;

    limpiarListaValor(lista);
}