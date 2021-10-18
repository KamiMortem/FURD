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
    void mostrar(tlistaValor lista, bool todo);

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
}

float PruebaEscritori::buscarUltimoValor(tlistaValor lista, tcad variable)
{
    pvalor i;
    float encontrado;
    if (lista.inicio != NULL)
        for (i = lista.inicio; i != NULL; i = i->sig)
            if (i->variable == variable)
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

void PruebaEscritori::mostrar(tlistaValor lista, bool todo)
{
    pvalor i, auxValor;
    int ultimo = 0;
    tcad variables[20];
    float valores[20];
    bool banderaJ;
    if (lista.inicio != NULL)
    {
        for (i = lista.inicio; i != NULL; i = i->sig)
        {
            if (todo)
            {
                cout << i->variable << "= " << i->valor << endl;
            }
            else
            {
                banderaJ = false;
                for (int j = 0; j < 20; j++)
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
        if (todo == false)
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

void PruebaEscritori::iniciaListaValor(tlistaValor &tlista)
{
    tlista.inicio = NULL;
    tlista.final = NULL;
    tlista.contador = 0;
}

void PruebaEscritori::iniciar()
{
    int opcion;
    tlistaValor lista;
    pvalor nuevo;

    iniciaListaValor(lista);

    do
    {
        crearValor(nuevo, lista);
        agregarFinal(lista, nuevo);
        do
        {
            mostrar(lista, false);
            cout << "Desea agregar un nuevo valor? 0:NO 1:SI" << endl;
            cin >> opcion;
        } while (opcion != 0 && opcion != 1);
    } while (opcion != 0);
    cout << "-----------------------------" << endl;
    mostrar(lista, true);
    cout << "-----------------------------" << endl;
}