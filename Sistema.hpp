class Sistema
{
private:
    /* data */
public:
    Sistema(/* args */);
    ~Sistema();
    void actualizarSistema();
    void calculadora();
};

Sistema::Sistema(/* args */)
{
}

Sistema::~Sistema()
{
}

void Sistema::actualizarSistema()
{
    int opcion;
    bool comandoBien=true;
    cout << "Sistema de archivos usado:" << endl;
    cout << "1- DEB" << endl;
    cout << "2- Pacman" << endl;
    cout << "3- dnf" << endl;

    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system("sudo apt-get update && sudo apt-get upgrade");
        break;
    case 2:
        system("sudo pacman -Syu");
        break;
    case 3:
        system("dnf update && sudo dnf upgrade");
        break;
    default:
        cout << "comando invalido" << endl;
        comandoBien=false;
        break;
    }
    if (comandoBien)
    {
        system("yay -Syua 2> /dev/null");
        system("yaourt -Syua 2> /dev/null");
        system("sudo snap refresh 2> /dev/null");
    }
}

void Sistema::calculadora(){
    system("calc");
}