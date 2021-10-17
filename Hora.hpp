
class Hora
{
private:
    /* data */
    float result;
    int hora;
    int minutos;
    int segundos;
    int horaTotalSegundos;

    void convertirTodoSegundos();

public:
    Hora(int hora, int minuto, int segundos);
    ~Hora();

    int getHora() { return this->hora; }
    int getMinutos() { return this->minutos; }
    int getSegundos() { return this->segundos; }
    int getTotalSegundos() { return this->horaTotalSegundos; }

    Hora dividirHora(int divisor);
    Hora sumarHora(Hora horOper);
    Hora restarHora(Hora horOper);
};

Hora::Hora(int hora, int minuto, int segundos)
{
    if (hora >= 0 && minuto <= 60 && segundos <= 60)
    {
        this->hora = hora;
        this->minutos = minuto;
        this->segundos = segundos;
        this->convertirTodoSegundos();
    }
    else
    {
        this->hora = -1;
        this->minutos = -1;
        this->segundos = -1;
        this->horaTotalSegundos = -1;
    }
}

Hora::~Hora()
{
}

void Hora::convertirTodoSegundos()
{
    this->horaTotalSegundos = (this->hora * 3600);
    this->horaTotalSegundos = this->horaTotalSegundos + (this->minutos * 60);
    this->horaTotalSegundos = this->horaTotalSegundos + (this->segundos);
}

Hora Hora::dividirHora(int divisor)
{
    int hor, min, seg, tot;

    tot = this->horaTotalSegundos / divisor;

    hor = tot / 3600;
    min = (tot % 3600) / 60;
    seg = ((tot % 3600) % 60);

    Hora horaAux(hor, min, seg);

    return horaAux;
}

Hora Hora::sumarHora(Hora horOper)
{
    int hor, min, seg, tot;

    tot = horOper.getTotalSegundos() + this->horaTotalSegundos;

    hor = tot / 3600;
    min = (tot % 3600) / 60;
    seg = ((tot % 3600) % 60);

    Hora horaTotal(hor, min, seg);
    return horaTotal;
}

Hora Hora::restarHora(Hora horOper)
{
    int hor, min, seg, tot;

    tot = horOper.getTotalSegundos() - this->horaTotalSegundos;

    hor = tot / 3600;
    min = (tot % 3600) / 60;
    seg = ((tot % 3600) % 60);

    Hora horaTotal(hor, min, seg);
    return horaTotal;
}